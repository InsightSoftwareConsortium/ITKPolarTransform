/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkCartesianToPolarTransform_hxx
#define itkCartesianToPolarTransform_hxx

#include "itkCartesianToPolarTransform.h"
#include "itkMath.h"

namespace itk
{

template<typename TParametersValueType, unsigned int NDimensions>
CartesianToPolarTransform<TParametersValueType, NDimensions>
::CartesianToPolarTransform()
{
}


template<typename TParametersValueType, unsigned int NDimensions>
CartesianToPolarTransform<TParametersValueType, NDimensions>
::~CartesianToPolarTransform()
{
}


template<typename TParametersValueType, unsigned int NDimensions>
void
CartesianToPolarTransform<TParametersValueType, NDimensions>
::PrintSelf(std::ostream &os, Indent indent) const
{
  Superclass::PrintSelf(os,indent);
}


template<typename TParametersValueType, unsigned int NDimensions>
typename CartesianToPolarTransform<TParametersValueType, NDimensions>::OutputPointType
CartesianToPolarTransform<TParametersValueType, NDimensions>
::TransformPoint(const InputPointType &inputPoint) const
{
  OutputPointType outputPoint( inputPoint );

  outputPoint[1] = std::sqrt( inputPoint[0] * inputPoint[0] + inputPoint[1] * inputPoint[1] );
  outputPoint[0] = std::acos( inputPoint[0] / outputPoint[1] );
  if( inputPoint[1] < 0 )
    {
    outputPoint[0] = Math::twopi - outputPoint[0];
    }

  return outputPoint;
}

} // namespace

#endif
