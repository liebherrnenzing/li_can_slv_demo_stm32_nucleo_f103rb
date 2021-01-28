from invoke import run, config, task, Collection
import os
import shutil

from configparser import *
import git
from git import *

@task
def diff(c):
    c.run("git difftool --dir-diff")
    c.run("git submodule foreach git difftool -d")


@task
def diff_origin(c):
    c.run("git difftool origin/master --dir-diff")
    c.run("git submodule foreach git difftool origin/master -d")

    
@task
def check(c):
    c.run("git submodule foreach git status")


@task
def update_all(c):
    c.run("git submodule update --remote")


@task(help={'submodule_name':"Name of the submodule to add."})
def add_submodule_from_base(c, submodule_name):
    for section, path, url, branch in get_submodule_from_base():
        if branch and url and path is not None:
            print("{} - {} - {} - {} \n".format(branch, url, path, submodule_name))
            if path==submodule_name:
                cmd = "git submodule add --force -b {0} {1} {2}".format(branch, url, path)
                c.run(cmd, warn=True)
                print("{} added\n".format(section))
                
@task
def add_submodules(ctx):
    for section, path, url, branch in get_submodule_from_base():
        if branch and url and path is not None:
            cmd = "git submodule add --force -b {0} {1} {2}".format(branch, url, path)
            print(cmd)
            ctx.run(cmd, warn=True)
            print("{} added\n".format(section))
        else:
            print("could not add {}\n".format(section))


@task
def remove_submodules(ctx):
    for section, path, url, branch in get_submodule_from_base():
        if branch and url and path is not None:
            cmd = "git submodule deinit -f -- {}".format(path)
            print(cmd)
            ctx.run(cmd, warn=True)
            cmd = "git rm -f {}".format(path)
            print(cmd)
            ctx.run(cmd, warn=True)

            cmd = "rm -rf .git/modules/{}".format(path)
            print(cmd)
            ctx.run(cmd, warn=True)

            print("{} removed\n".format(section))
        else:
            print("could not remove {}\n".format(section))


@task
def remove_all_submodules(ctx):
    repo = Repo(".")
    sub_modules = repo.submodules
    print("\n")
    print(sub_modules)
    print("\n")
    for sm in sub_modules:
        print("remove: {}".format(sm.name))
        sm.remove(True, force=True)


@task
def remove_submodule(ctx, submodule_name):
    repo = Repo(".")
    sub_modules = repo.submodules
    for sm in sub_modules:
        if sm.name == submodule_name:
            print("remove: {}".format(sm.name))
            sm.remove(True, force=True)


@task
def show_all_submodules(ctx):
    repo = Repo(".")
    sub_modules = repo.submodules
    for sm in sub_modules:
        print(sm.name)


def get_submodule_from_base():
    config = ConfigParser()
    config.read('gitmodules_base')
    for section in config.sections():
        _path = get_value_with_default(config, section, 'path', None)
        _url = get_value_with_default(config, section, 'url', None)
        _branch = get_value_with_default(config, section, 'branch', None)
        yield section, _path, _url, _branch


def get_value_with_default(config, section, name, default):
    if config.has_option(section, name):
        return config.get(section, name)
    else:
        return default
