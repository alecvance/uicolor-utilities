//
//  UIColor-Expanded.h
//  Aquarium
//
//  Created by Alec Vance on 9/14/10.
//  Copyright 2010 Juggleware, LLC. All rights reserved.
//
//based on code from Erica Sadun at http://arstechnica.com/apple/guides/2009/02/iphone-development-accessing-uicolor-components.ars
//
// forked from https://github.com/thetaplab/uicolor-utilities
//

#import <UIKit/UIKit.h>

#define SUPPORTS_UNDOCUMENTED_API	0

@interface UIColor (UIColor_Expanded)
@property (nonatomic, readonly) CGColorSpaceModel colorSpaceModel;
@property (nonatomic, readonly) BOOL canProvideRGBComponents;
@property (nonatomic, readonly) CGFloat red; // Only valid if canProvideRGBComponents is YES
@property (nonatomic, readonly) CGFloat green; // Only valid if canProvideRGBComponents is YES
@property (nonatomic, readonly) CGFloat blue; // Only valid if canProvideRGBComponents is YES
@property (nonatomic, readonly) CGFloat white; // Only valid if colorSpaceModel == kCGColorSpaceModelMonochrome
@property (nonatomic, readonly) CGFloat alpha;
@property (nonatomic, readonly) UInt32 rgbHex;

- (NSString *)colorSpaceString;

- (NSArray *)arrayFromRGBAComponents;

- (BOOL)red:(CGFloat *)r green:(CGFloat *)g blue:(CGFloat *)b alpha:(CGFloat *)a;

- (UIColor *)colorByLuminanceMapping;

- (UIColor *)colorByMultiplyingByRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
- (UIColor *)       colorByAddingRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
- (UIColor *) colorByLighteningToRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
- (UIColor *)  colorByDarkeningToRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;

- (UIColor *)colorByMultiplyingBy:(CGFloat)f;
- (UIColor *)       colorByAdding:(CGFloat)f;
- (UIColor *) colorByLighteningTo:(CGFloat)f;
- (UIColor *)  colorByDarkeningTo:(CGFloat)f;

- (UIColor *)colorByMultiplyingByColor:(UIColor *)color;
- (UIColor *)       colorByAddingColor:(UIColor *)color;
- (UIColor *) colorByLighteningToColor:(UIColor *)color;
- (UIColor *)  colorByDarkeningToColor:(UIColor *)color;

//added by Alec 2010-09-16
- (UIColor *) colorByMixingWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
- (UIColor *) colorByMixingWithColor:(UIColor *)color;

- (NSString *)stringFromColor;
- (NSString *)hexStringFromColor;

+ (UIColor *)randomColor;
+ (UIColor *)colorWithString:(NSString *)stringToConvert;
+ (UIColor *)colorWithRGBHex:(UInt32)hex;
+ (UIColor *)colorWithHexString:(NSString *)stringToConvert;

+ (UIColor *)colorWithName:(NSString *)cssColorName;
+(UIColor *)colorBetweenColor:(UIColor *)color1 andColor:(UIColor *)color2 onSpectrumAt:(CGFloat)position;

@end

#if SUPPORTS_UNDOCUMENTED_API
// UIColor_Undocumented_Expanded
// Methods which rely on undocumented methods of UIColor
@interface UIColor (UIColor_Undocumented_Expanded)
- (NSString *)fetchStyleString;
- (UIColor *)rgbColor; // Via Poltras
@end
#endif // SUPPORTS_UNDOCUMENTED_API
