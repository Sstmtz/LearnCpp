project(
  'hello',
  'c',
  version: run_command('cat', join_paths(meson.project_source_root(), 'VERSION'), check: true).stdout().strip(),
  default_options: [
    'warning_level=2',
  ],
)

add_project_arguments(
  [],
  language: 'c',
)

# version = run_command('git', 'rev-parse', 'HEAD', check: true, capture: true).stdout().strip()

vcs_dep = vcs_tag(
  command: ['git', 'rev-parse', 'HEAD'],
  input: 'version.h.in',
  output: 'version.h',
  replace_string: '@GIT_COMMIT_HASH@',
)

src = ['main.c', 'hello.c']

executable(
  'hello',
  src,
  vcs_dep,
  install: true,
  # c_args: '-DGIT_COMMIT_HASH="' + meson.project_version() + '"',
  # c_args: '-DGIT_COMMIT_HASH="' + version + '"',
)
