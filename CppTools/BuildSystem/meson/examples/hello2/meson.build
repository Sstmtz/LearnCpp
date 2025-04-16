project(
  'hello2',
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

# Install headers
globber = run_command('find', 'src', '-name', '*.h', check: true)
headers = globber.stdout().strip().split('\n')
foreach file : headers
  install_headers(file, subdir: 'hello2', preserve_path: true)
endforeach

subdir('src')
