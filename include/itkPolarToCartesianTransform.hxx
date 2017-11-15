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
#ifndef itkPolarToCartesianTransform_hxx
#define itkPolarToCartesianTransform_hxx

#include "itkPolarToCartesianTransform.h"

namespace itk
{

template< typename TParametersValueType, unsigned int NDimensions >
PolarToCartesianTransform<TParametersValueType, NDimensions>
::PolarToCartesianTransform()
{
  this->m_Center.Fill( 0.0 );
}


template<typename TParametersValueType, unsigned int NDimensions>
PolarToCartesianTransform<TParametersValueType, NDimensions>
::~PolarToCartesianTransform()
{
}


template<typename TParametersValueType, unsigned int NDimensions>
void
PolarToCartesianTransform<TParametersValueType, NDimensions>
::PrintSelf(std::ostream &os, Indent indent) const
{
  Superclass::PrintSelf(os,indent);
  os << indent << "Center: " << m_Center << std::endl;
}


template<typename TParametersValueType, unsigned int NDimensions>
typename PolarToCartesianTransform<TParametersValueType, NDimensions>::OutputPointType
PolarToCartesianTransform<TParametersValueType, NDimensions>
::TransformPoint(const InputPointType & inputPoint) const
{
  OutputPointType outputPoint(inputPoint);

  outputPoint[0] = inputPoint[1] * std::cos(inputPoint[0]); //r*cos(alpha)
  outputPoint[1] = inputPoint[1] * std::sin(inputPoint[0]); //r*sin(alpha)

  for( unsigned int ii = 0; ii < SpaceDimension; ++ii )
    {
    outputPoint[ii] = this->m_Center[ii] + outputPoint[ii];
    }

  return outputPoint;
}

} // namespace itk

#endif
