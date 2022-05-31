ITKPolarTransform
=================

.. image:: https://github.com/InsightSoftwareConsortium/ITKPolarTransform/workflows/Build,%20test,%20package/badge.svg

Overview
--------

This is a module for the `Insight Toolkit (ITK) <https://www.itk.org>`_
to transform from cartesian to polar coordinate systems and back.

For more information, see the `Insight Journal article <https://hdl.handle.net/1926/342>`_::

  Bican J.
  Polar Transforms for ITK
  The Insight Journal. July-December. 2006.
  https://hdl.handle.net/1926/342
  https://insight-journal.org/browse/publication/130

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
