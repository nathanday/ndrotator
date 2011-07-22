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

/**
	@header NDRotatorStyle.h
	@abstract Header file for the class <NDRotator>
	@version 0.0.9
 */

#import <UIKit/UIKit.h>

/**
	@enum NDRotatorStyle
	@abstract Constants used to control the way <NDRotator> interacts with the user.
	@constant NDRotatorStyleDisc With the disc style the user can move the control thumb through two axises, <angle> and <radius>.
	@constant NDRotatorStyleRotate With the rotate style the user can only move the control through one axises, <angle>, the <radius> value is always 1.0.
	@constant NDRotatorStyleLinear The linear style is similar to the rotate style but the user can change the angular value with a vertical movement, the <radius> value is always 1.0, the sensitivity is <linearSensitivity> property.
 */
enum NDRotatorStyle
{
	NDRotatorStyleDisc,
	NDRotatorStyleRotate,
	NDRotatorStyleLinear
};

/**
Constants used to change the thumb tint, this can be used to make the thumb clearer for smaller rotator controls.
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

/**
A NDRotator object is a visual control used to select one or two values from a continuous range of values. Rotator are always displayed as circular dials. An indicator, or thumb, notes the current value of the rotator and can be moved by the user to change the setting with a turning action and the choice of radius action as well for a second value.

### Subclassing Notes
The NDRotator class is designed to be subclassed to change the appearance. NDRotator performs caching of it elements to allow for smooth animation on low power devices like the iPhone, the methods to override work with this caching so you do not have to reimplement this yourself.

#### Methods to Override
 
When subclassing NDRotator, there are only a handful of methods you need to override. NDRotator is designed to do as much as possible to implement you own rotator style control, it is based around a control made up of two parts which do not change appearance for changing values but instead the position of a thumb element changes with respect to the body of the control.
if you need to, you can override any of the following methods in your NDRotator subclasses:

- Initialization:
	initWithFrame:, initWithCoder: -Just like subclassing and <UIView> you may want to override the initialisation methods initWithFrame: and initWithCoder: to add the initialisation of you own properties.
- Coding:
	initWithCoder:, encodeWithCoder: -If you want to add your own values to be encoded and decoded you will then have to override these two methods you should call the super implementation.
- Drawing:
	drawBodyInRect:hilighted:, drawThumbInRect:hilighted: -you will need to override these two methods to change the appearance of Rotator's, unless you want to just modify the default look, for example you could just override drawThumbInRect:hilighted: if you just want to change the thumb but keep the same body, you do no want to call the super implementations in your implementations.
	bodyRect, thumbRect -If you override <drawBodyInRect:hilighted:> <drawThumbInRect:hilighted:>, you will need to override the corresponding rect property to give NDRotator information on how to calculating the thumb position.
- Behaviour:
	setStyle: -This method is can be overriden if want to limit which styles are supported, for example, the <NDRotatorStyleDisc> style offten will not be appropriate, if you are the only user of your subclass, then this is not nessecary as you can choose to just not use it this way.

 */
@interface NDRotator : UIControl <NSCoding>

/**
 @name Accessing the Rotator’s Value
 */
/**
This is a value taken from the <angle> property and mapped from the domain (<minimumDomain>,<maximumDomain>) to the range (<minimumValue>,<maximumValue>).
 */
@property(assign)	CGFloat			value;
/**
 Contains the angle of the receiver in radians.
 
 This value will be constrained by the values (<minimumDomain>,<maximumDomain>) and so can represent a range of values greater than one turn.
 */
@property(assign,nonatomic)	CGFloat			angle;
/**
 Contains the radius value of the receiver where 0.0 puts the thumb at the center and 1.0 puts the thumb at margin.
 
 The values can be greater than 1.0, to reflect user movements outside of the control.
 */
@property(assign,nonatomic)	CGFloat			radius;
/**
 Contains the thumb point where (0.0,0.0) is the center, (1.0,0.0) is at 3 oclock and (0.0,-1.0) is at 12 oclock etc.
 
 The point can go beyound the bounds (-1.0,-1.0) and (1.0,1.0) for <radius> values greated the 1.0.
 */
@property(assign)	CGPoint				cartesianPoint;
/**
 Contains the thumb point where (0.0,0.0) is the center, (1.0,0.0) is at 3 oclock and (0.0,-1.0) is at 12 oclock etc. The value is generated from a <radius> constrained to (0.0,1.0).
 
 This value is similar to <cartesianPoint> give a <radius> constrained to (0.0,1.0).
 */
@property(readonly)	CGPoint				constrainedCartesianPoint;

/**
 @name Accessing the Rotator’s Value Limits
 */

/**
Contains the minimum value of the receiver.
If you change the value of this property, and the current <value> of the receiver is below the new minimum, the current <value> is adjusted to match the new minimum value automatically.

The default value of this property is 0.0.
 */
@property(assign)	CGFloat				minimumValue;
/**
Contains the maximum value of the receiver.
If you change the value of this property, and the current <value> of the receiver is above the new maximum, the current <value> is adjusted to match the new maximum value automatically.

The default value of this property is 1.0.
 */
@property(assign)	CGFloat				maximumValue;
/**
Contains the minimum <angle> of the receiver.
The default value of this property is 0.0.
 */
@property(assign)	CGFloat				minimumDomain;
/**
Contains the maximum <angle> of the receiver.
The default value of this property is 2.0pi.
*/
@property(assign)	CGFloat				maximumDomain;
/**
Contains the value used to determin how vertical movement is mapped to angular movement of the control when the style is <NDRotatorStyleLinear>.
The <angle> is propertional to y-value * <linearSensitivity>.
The default value of this property is 0.05.
 */

/**
	@name Modifying the Rotator’s Behavior
 */
@property(assign)	CGFloat				linearSensitivity;
/**
Contains the enum value used to determine how the reciever interacts with the user.
 */
@property			enum NDRotatorStyle			style;
/**
Contains the boolean used to determine how the rotator behaves when the user reaches <minimumDomain> or <maximumDomain>.

If <wrapAround> is YES then when the <angle> value reaches <minimumDomain> the <angle> value continues by wrapping the value up to <maximumDomain>, and similarly when the <angle> value reaches <maximumDomain> the <angle> value continues by wrapping the value down to <minimumDomain>. If NO then the rotator will simple stop when the <minimumDomain> or <maximumDomain> is reached. If <wrapAround> is YES and the difference between <minimumDomain> and <maximumDomain> is not exactly a multiple 2π then an undesired jump may occur.
 
The default value of this property is YES.
 */
@property			BOOL						wrapAround;
/**
Contains a boolean value indicating whether changes in the sliders value generate continuous update events.

If YES, the slider sends update events continuously to the associated target's action method. If NO, the slider only sends an action event when the user releases the slider’s thumb control to set the final value.
 
The default value of this property is YES.
 */
@property(nonatomic, getter=isContinuous) BOOL	continuous;

/**
	@name Changing the Rotator’s Appearance
 */
/**
Contains the value used to set the color of the thumb.

The default value of the property is <NDThumbTintGrey>.
 */
@property(nonatomic)		enum NDThumbTint	thumbTint;

/**
 @name Methods to call when subclassing
 */

/**
 Delete the thumb cache causing it to be recalculated
 This method is for subclass to call if the thumb images changes and needs to be redrawn
 */
- (void)deleteThumbCache;
/**
 Delete the disc cache causing it to be recalculated
 This method is for subclass to call if the disc images changes and needs to be redrawn
 */
- (void)deleteBodyCache;

/**
 @name Methods and properties to override when subclassing
 */

/**
 The rect used for the controls body.
 This rect may be smaller than the bounds of the control to allow for shadow effects. This rect is used to workout where the thumb position, the center of the rect is the point which the thumb rotates around.
 */
@property(readonly) CGRect		bodyRect;
/**
 The rect used to contain the thumb image.
 This point (0.0,0.0) in the rect used to position the thumb, for a symetrical thumb the point (0.0,0.0) is the center of the rect.
 */
@property(readonly) CGRect		thumbRect;

/**
draw the control body into the given <rect>.
The <rect> supplied is the size of the reciever <bounds> of the control not the rect returned from the property <bodyRect>. The drawing is cached and so is not called all the time, to force the body to be redrawed again call <deleteBodyCache>. This methods is called twice, <hilighted> set and unset, if there is no difference between the two versions then return NO for one of the versions this will result in one version being used for both hilighted and unhilighted.
 */
- (BOOL)drawBodyInRect:(CGRect)rect hilighted:(BOOL)hilighted;
/**
 draw the control thumb into the given rect.
 The <rect> supplied is the size of the rect returned from <thumbRect>, but the origin is not. The drawing is cahced and so is not called all the time, to force the thumb to be redrawed again call <deleteThumbCache>. This methods is called twice, <hilighted> set and unset, if there is no difference between the two versions then return NO for one of the versions this will result in one version being used for both hilighted and unhilighted.
 */
- (BOOL)drawThumbInRect:(CGRect)rect hilighted:(BOOL)hilighted;

@end
