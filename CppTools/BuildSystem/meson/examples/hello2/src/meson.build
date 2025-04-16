# src = ['main.c', 'hello.c']
globber = run_command('sh', '-c', 'find . -name "*.c" | sort', check: true)
src = globber.stdout().strip().split('\n')

vcs_dep = vcs_tag(
  command: ['git', 'rev-parse', 'HEAD'],
  input: 'version.h.in',
  output: 'version.h',
  replace_string: '@GIT_COMMIT_HASH@',
)

executable('hello2', src, vcs_dep, install: true)
