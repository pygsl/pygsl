#: Todo: revisit if there is a more elegant way for this
py_sources = run_command('find',
['.',  '-maxdepth', '1', '-name', '*.py'],
  check : true
).stdout().strip().split('\n')

py.install_sources(
  py_sources,
  pure: false,
  subdir: 'pygsl'
)

subdir('statistics')
subdir('testing')
