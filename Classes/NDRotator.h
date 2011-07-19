/*
	NDRotator.h

	Created by Nathan Day on 7.07.11 under a MIT-style license.
	Copyright (c) 2011 Nathan Day

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.
 */

/*!
	@header NDRotatorStyle.h
	@abstract Header file for the class <tt>NDRotatorStyle</tt>
	@version 0.0.9
 */

#import <UIKit/UIKit.h>

/*!
	@enum NDRotatorStyle
	@abstract Constants used to control the way NDRotator interacts with the user.
	@constant NDRotatorStyleDisc With the disc style the user can move the control thumb through two axises, angular and radial.
	@constant NDRotatorStyleRotate With the rotate style the user can only move the control through one axises, angular, the radial value is always 1.0.
	@constant NDRotatorStyleLinear The linear style is similar to the rotate style but the user can change the angular value with a vertical movement, the sensitivity is linearSensitivity property.
 */
enum NDRotatorStyle
{
	NDRotatorStyleDisc,
	NDRotatorStyleRotate,
	NDRotatorStyleLinear
};

/*!
 @enum NDThumbTint
 @abstract Constants used to change the thumb tint, this can be used to make the thumb clearer for smaller rotator controls.
 */
enum NDThumbTint
{
	NDThumbTintGrey,
	NDThumbTintRed,
	NDThumbTintGreen,
	NDThumbTintBlue,
	NDThumbTintYellow,
	NDThumbTintMagenta,
	NDThumbTintTeal,
	NDThumbTintOrange,
	NDThumbTintPink,
	NDThumbTintLime,
	NDThumbTintSpringGreen,
	NDThumbTintPurple,
	NDThumbTintAqua,
	NDThumbTintBlack
};

/*!
	@class NDRotator
	@abstract A NDRotator object is a visual control used to select one or two values from a continuous range of values. Rotator are always displayed as circular dials. An indicator, or thumb, notes the current value of the rotator and can be moved by the user to change the setting with a turning action and the choice of radius action as well for a second value.
	@discussion NDRotator is designed to be overridden to change the appearance there, MORE TO COME.
 */
@interface NDRotator : UIControl

/*!
	@property value
	This is a value taken from the angle property and mapped from the domain {minimumDomain,maximumDomain} to the range {minimumValue,maximumValue}.
 */
@property(assign)	CGFloat						value;
/*!
	@property minimumValue
	@abstract Contains the minimum value of the receiver.
	@discussion If you change the value of this property, and the current value of the receiver is below the new minimum, the current value is adjusted to match the new minimum value automatically.

	The default value of this property is 0.0.
 */
@property(assign)	CGFloat						minimumValue;
/*!
	@property maximumValue
	@abstract Contains the maximum value of the receiver.
	@discussion If you change the value of this property, and the current value of the receiver is above the new maximum, the current value is adjusted to match the new maximum value automatically.

	The default value of this property is 1.0.
 */
@property(assign)	CGFloat						maximumValue;
/*!
	@property minimumDomain
	@abstract Contains the minimum angle of the receiver.
	@discussion 

	The default value of this property is 0.0.
 */
@property(assign)	CGFloat						minimumDomain;
/*!
	@property maximumDomain
	@abstract Contains the maximum angle of the receiver.
	@discussion 

	The default value of this property is 2.0π.
*/
@property(assign)	CGFloat						maximumDomain;
/*!
	@property linearSensitivity
	@abstract Contains the value used to determin how vertical movement is mapped to angular movement of the control when the style is NDRotatorStyleLinear.
	@discussion The angle is propertional to y-value * linearSensitivity.

	The default value of this property is 0.05.
 */
@property(assign)	CGFloat						linearSensitivity;
/*!
	@property angle
	@abstract Contains the angle of the receiver in radians.
	@discussion This value will be constrained by the values (minimumDomain,maximumDomain) and so can represent a range of values greater than one turn.
 */
@property(assign,nonatomic)	CGFloat				angle;
/*!
	@property radius
	@abstract Contains the radial value of the receiver where 0.0 puts the thumb at the center and 1.0 puts the thumb at margin.
	@discussion The values can be greater than 1.0, to reflect user movements outside of the control.
 */
@property(assign,nonatomic)	CGFloat				radius;
/*!
	@property cartesianPoint
	@abstract Contains the thumb point where (0.0,0.0) is the center, (1.0,0.0) is at 3 oclock and (0.0,-1.0) is at 12 oclock etc.
	@discussion The point can go beyound the bounds (-1.0,-1.0) and (1.0,1.0) for radius values greated the 1.0.
  */
@property(assign)	CGPoint						cartesianPoint;
/*!
	@property constrainedCartesianPoint
	@abstract Contains the thumb point where (0.0,0.0) is the center, (1.0,0.0) is at 3 oclock and (0.0,-1.0) is at 12 oclock etc. Constrained to a raius of 1.0.
	@discussion Ths value is similar to cartesianPoint give a radius constrained to (0.0,1.0).
 */
@property(readonly)	CGPoint						constrainedCartesianPoint;
/*!
	@property style
	@abstract Contains the enum value used to determine how the reciever interacts with the user.
 */
@property			enum NDRotatorStyle			style;
/*!
	@property wrapAround
	@abstract Contains the boolean used to determine how the rotator behaves when the user reaches minimumDomain or maximumDomain.
	@discussion If wrapAround is YES then when the angular value reaches minimumDomain the angular value continues by wrapping the value up to maximumDomain, and similarly when the angular value reaches maximumDomain the angular value continues by wrapping the value down to minimumDomain. If NO then the rotator will simple stop when the minimumDomain or maximumDomain is reached. If wrapAround is YES and the difference between minimumDomain and maximumDomain is not exactly a multiple 2π then an undesired jump may occur.
 
	The default value of this property is YES.
 */
@property			BOOL						wrapAround;
/*!
	@property continuous
	@abstract Contains a Boolean value indicating whether changes in the sliders value generate continuous update events.
	@discussion If YES, the slider sends update events continuously to the associated target’s action method. If NO, the slider only sends an action event when the user releases the slider’s thumb control to set the final value.
 
	The default value of this property is YES.
 */
@property(nonatomic, getter=isContinuous) BOOL	continuous;
/*!
	@property thumbTint
	@abstract Contains the value used to set the color of the thumb.
	@discussion

	The default value of the property is NDThumbTintGrey.
 */
@property(nonatomic)		enum NDThumbTint	thumbTint;

/*!
	@methodgroup methods and properties to override to change the apperance of a NDRotator, these methods are not yet finalized.
 */

@property(readonly) CGRect		controlRect;
@property(readonly) CGRect		thumbRect;

- (BOOL)drawDiscInRect:(CGRect)rect hilighted:(BOOL)hilighted;
- (BOOL)drawThumbInRect:(CGRect)rect hilighted:(BOOL)hilighted;

@end
