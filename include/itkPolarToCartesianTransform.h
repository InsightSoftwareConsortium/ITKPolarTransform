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
#ifndef itkPolarToCartesianTransform_h
#define itkPolarToCartesianTransform_h

#include <iostream>
#include "itkTransform.h"
#include "itkMacro.h"
#include "itkMatrix.h"

namespace itk
{

/** \class PolarToCartesianTransform
 *
 * \brief Polar transformation of a vector space (e.g. space coordinates).
 *
 * Transforms first two coordinates form polar space <alpha,radius> to cartesian
 * coordinates. Other dimensions are left unchanges. In fact this is generalized
 * cylindric transform:
 * \f[          x_1 = r cos( \alpha ) \f]
 * \f[          x_2 = r sin( \alpha ) \f]
 * \f[          x_n = x_n, \mbox{ n>=2 } \f]
 *
 * \par
 * Center of the polar transform is can be specified with SetCenter().
 * The default is center of coordinate system < 0, 0 >.
 *
 * Dimension must be at least 2.
 *
 * Extent of input in first dimension (alpha) should be only < 0, 2*pi ).
 *
 * \author Jakub Bican, Department of Image Processing, Institute of Information Theory and Automation, Academy of Sciences of the Czech Republic.
 *
 * \ingroup Transforms
 * \ingroup PolarTransform
 */
template < typename TParametersValueType=double,          // Data type for scalars (float or double)
    unsigned int NDimensions=3 >        // Number of dimensions
class ITK_TEMPLATE_EXPORT PolarToCartesianTransform:
  public Transform< TParametersValueType, NDimensions, NDimensions >
{
public:
  ITK_DISALLOW_COPY_AND_ASSIGN(PolarToCartesianTransform);

  /** Standard class type alias. */
  using Self = PolarToCartesianTransform;
  using Superclass = Transform< TParametersValueType, NDimensions, NDimensions >;
  using Pointer = SmartPointer< Self >;
  using ConstPointer = SmartPointer< const Self >;

  /** New macro for creation of through the object factory.*/
  itkNewMacro( Self );

  /** Run-time type information (and related methods). */
  itkTypeMacro( PolarToCartesianTransform, Transform );

  /** Dimension of the domain space. */
  static constexpr unsigned int SpaceDimension = NDimensions;
  static constexpr unsigned int ParametersDimension = 0;

  /** Standard scalar type for this class. */
  using ScalarType = typename Superclass::ScalarType;

  /** Standard Jacobian container. */
  using JacobianType = typename Superclass::JacobianType;

  /** Standard parameters container. */
  using ParametersType = typename Superclass::ParametersType;

  /** Standard vector type for this class. */
  using InputVectorType = Vector<TParametersValueType, itkGetStaticConstMacro(SpaceDimension)>;
  using OutputVectorType = Vector<TParametersValueType, itkGetStaticConstMacro(SpaceDimension)>;

  /** Standard covariant vector type for this class. */
  using InputCovariantVectorType = CovariantVector<TParametersValueType, itkGetStaticConstMacro(SpaceDimension)>;
  using OutputCovariantVectorType = CovariantVector<TParametersValueType, itkGetStaticConstMacro(SpaceDimension)>;

  /** Standard vnl_vector type for this class. */
  using InputVnlVectorType = vnl_vector_fixed<TParametersValueType, itkGetStaticConstMacro(SpaceDimension)>;
  using OutputVnlVectorType = vnl_vector_fixed<TParametersValueType, itkGetStaticConstMacro(SpaceDimension)>;

  /** Standard coordinate point type for this class. */
  using InputPointType = Point<TParametersValueType, itkGetStaticConstMacro(SpaceDimension)>;
  using OutputPointType = Point<TParametersValueType, itkGetStaticConstMacro(SpaceDimension)>;

  /** Method to transform a point.
   * This method transforms first two dimensions of a point from polar
   * coordinates <alpha,radius> to cartesian coordinates.
   */
  OutputPointType TransformPoint(const InputPointType  &point ) const override;

  /** Method to transform a vector - not applicable for this type of transform. */
  OutputVectorType TransformVector(const InputVectorType &) const override
    {
    itkExceptionMacro(<< "Method not applicable for this type of transform.");
    return OutputVectorType();
    }

  /** Method to transform a vnl_vector - not applicable for this type of transform. */
  OutputVnlVectorType TransformVector(const InputVnlVectorType &) const override
    {
    itkExceptionMacro(<< "Method not applicable for this type of transform.");
    return OutputVnlVectorType();
    }

  /** Method to transform a vector - not applicable for this type of transform. */
  typename Superclass::OutputVectorPixelType TransformVector(
      const typename Superclass::InputVectorPixelType &, const InputPointType &) const override
    {
    itkExceptionMacro(<< "Method not applicable for this type of transform.");
    return typename Superclass::OutputVectorPixelType();
    }

  using Superclass::TransformVector;

  /** Method to transform a CovariantVector - not applicable for this type of transform */
  OutputCovariantVectorType TransformCovariantVector(
    const InputCovariantVectorType &) const override
    {
    itkExceptionMacro(<< "Method not applicable for this type of transform.");
    return OutputCovariantVectorType();
    }

  using Superclass::TransformCovariantVector;

  void ComputeJacobianWithRespectToParameters( const InputPointType &, JacobianType & ) const override
    {
    itkExceptionMacro(<< "Method not implemented yet.");
    }

  void SetParameters(const ParametersType &) override {}

  void SetFixedParameters(const ParametersType &) override {}

  /** Set the location of the center of the polar coordinate system. */
  itkSetMacro( Center, OutputPointType );
  itkGetConstReferenceMacro( Center, OutputPointType );

  /** Set an angular offset for the polar coordinate transform. 
   *
   * Defaults to 0.0
   */
  itkSetMacro( AngleOffset, typename InputPointType::ValueType );
  itkGetConstReferenceMacro( AngleOffset, typename InputPointType::ValueType );

  /** Enable/Disable to use constant arc increment instead of constant angular increment.
   *
   * Defaults to Off
   */
  itkSetMacro(ConstArcIncr, bool);
  itkGetMacro(ConstArcIncr, bool);
  itkBooleanMacro(ConstArcIncr);

  /** Enable/Disable to return NaN in case alpha is outside [-pi,pi].
   *
   * Defaults to Off
   */
  itkSetMacro(ReturnNaN, bool);
  itkGetMacro(ReturnNaN, bool);
  itkBooleanMacro(ReturnNaN);

protected:
  PolarToCartesianTransform();
  ~PolarToCartesianTransform() override;

  /** Print contents of an PolarToCartesianTransform. */
  void PrintSelf(std::ostream &os, Indent indent) const override;

private:
  OutputPointType m_Center;
  typename InputPointType::ValueType m_AngleOffset = 0;
  bool m_ConstArcIncr = false;
  bool m_ReturnNaN = false;
}; //class PolarToCartesianTransform

}  // namespace itk


#ifndef ITK_MANUAL_INSTANTIATION
#include "itkPolarToCartesianTransform.hxx"
#endif

#endif
