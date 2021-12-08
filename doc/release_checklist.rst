Checklist for releasing a new version on PyPI
---------------------------------------------

- Adapt the version numbers in ``pygsl/_version.py`` and ``setup.cfg``

- Build the wheels

  .. code-block:: sh

     python setup.py sdist

- Do a test upload

  .. code-block:: sh

     twine upload --repository testpypi dist/* 

- Try to install it from a docker image

  .. code-block:: sh

     python3 -m pip install --index-url https://test.pypi.org/simple/ pygsl

- Clone the repository and run the tests via pytest

- Happy? Push to non-testing repository
