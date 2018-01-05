ITKPolarTransform
=================================

.. image:: https://circleci.com/gh/InsightSoftwareConsortium/ITKPolarTransform.svg?style=shield
    :target: https://circleci.com/gh/InsightSoftwareConsortium/ITKPolarTransform

.. image:: https://travis-ci.org/InsightSoftwareConsortium/ITKPolarTransform.svg?branch=master
    :target: https://travis-ci.org/InsightSoftwareConsortium/ITKPolarTransform

.. image:: https://img.shields.io/appveyor/ci/itkrobot/itkpolartransform.svg
    :target: https://ci.appveyor.com/project/itkrobot/itkpolartransform

Overview
--------

This is a module for the `Insight Toolkit (ITK) <https://www.itk.org>`_
to transform from cartesian to polar coordinate systems and back.

For more information, see the `Insight Journal article <http://hdl.handle.net/1926/342>`_::

  Bican J.
  Polar Transforms for ITK
  The Insight Journal. July-December. 2006.
  http://hdl.handle.net/1926/342
  http://insight-journal.org/browse/publication/130

Installation
------------

Python
^^^^^^

Binary `Python packages <https://pypi.python.org/pypi/itk-polartransform>`_
are available for Linux, macOS, and Windows. They can be installed with::

  python -m pip install --upgrade pip
  python -m pip install itk-polartransform


C++
^^^

Since ITK 5.0.0, this module is available in the ITK source tree as a Remote
module. To enable it, set::

  Module_PolarTransform:BOOL=ON

in ITK's CMake build configuration.

License
-------

This software is distributed under the Apache 2.0 license. Please see
the *LICENSE* file for details.
