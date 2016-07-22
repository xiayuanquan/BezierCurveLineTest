//
//  BezierCurveView.h
//  BezierCurveLineDemo
//
//  Created by mac on 16/7/20.
//  Copyright © 2016年 xiayuanquan. All rights reserved.
//

/*
 UIBezierPath ：画贝塞尔曲线的path类
 UIBezierPath定义 ： 贝赛尔曲线的每一个顶点都有两个控制点，用于控制在该顶点两侧的曲线的弧度。
 曲线的定义有四个点：起始点、终止点（也称锚点）以及两个相互分离的中间点。
 滑动两个中间点，贝塞尔曲线的形状会发生变化。
 UIBezierPath ：对象是CGPathRef数据类型的封装，可以方便的让我们画出 矩形 、 椭圆 或者 直线和曲线的组合形状
 
 初始化方法：
 + (instancetype)bezierPath;
 
 //创建一个矩形
 + (instancetype)bezierPathWithRect:(CGRect)rect;
 
 //创建圆形或者椭圆形
 + (instancetype)bezierPathWithOvalInRect:(CGRect)rect;
 + (instancetype)bezierPathWithRoundedRect:(CGRect)rect cornerRadius:(CGFloat)cornerRadius; // rounds all corners with the same horizontal and vertical radius
 + (instancetype)bezierPathWithRoundedRect:(CGRect)rect byRoundingCorners:(UIRectCorner)corners cornerRadii:(CGSize)cornerRadii;
 + (instancetype)bezierPathWithArcCenter:(CGPoint)center radius:(CGFloat)radius startAngle:(CGFloat)startAngle endAngle:(CGFloat)endAngle clockwise:(BOOL)clockwise;
 + (instancetype)bezierPathWithCGPath:(CGPathRef)CGPath;
 
 最基本的使用方法是：
 //设置描绘的起点
 - (void)moveToPoint:(CGPoint)point;
 
 //画直线
 - (void)addLineToPoint:(CGPoint)point;
 
 //画曲线
 (1)绘制二次贝塞尔曲线   分别对应终点和一个控制点
 - (void)addQuadCurveToPoint:(CGPoint)endPoint controlPoint:(CGPoint)controlPoint
 
 (1)绘制三次贝塞尔曲线   分别对应终点和两个控制点
 - (void)addCurveToPoint:(CGPoint)endPoint controlPoint1:(CGPoint)controlPoint1 controlPoint2:(CGPoint)controlPoint2;
 
 //画圆弧
 - (void)addArcWithCenter:(CGPoint)center radius:(CGFloat)radius startAngle:(CGFloat)startAngle endAngle:(CGFloat)endAngle clockwise:(BOOL)clockwise
 
 使用贝塞尔曲线的基本步骤是：
    (1）创建一个Bezier path对象。
   （2）使用方法moveToPoint:去设置初始线段的起点。
   （3）添加line或者curve去定义一个或者多个subpaths。
   （4）改变UIBezierPath对象跟绘图相关的属性。
 */

#import <UIKit/UIKit.h>

#define MARGIN            30   // 坐标轴与画布间距
#define Y_EVERY_MARGIN    20   // y轴每一个值的间隔数

// 颜色RGB
#define XYQColor(r, g, b)  [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define XYQColorRGBA(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:a]

// 随机色
#define XYQRandomColor  XYQColor(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256))

// 线条类型
typedef NS_ENUM(NSInteger, LineType) {
    LineType_Straight, // 折线
    LineType_Curve     // 曲线
};

@interface BezierCurveView : UIView

//初始化画布
+(instancetype)initWithFrame:(CGRect)frame;


/**
 *  画折线图
 *  @param x_names      x轴值的所有值名称
 *  @param targetValues 所有目标值
 *  @param lineType     直线类型
 */
-(void)drawLineChartViewWithX_Value_Names:(NSMutableArray *)x_names TargetValues:(NSMutableArray *)targetValues LineType:(LineType) lineType;


/**
 *  画柱状图
 *  @param x_names      x轴值的所有值名称
 *  @param targetValues 所有目标值
 */
-(void)drawBarChartViewWithX_Value_Names:(NSMutableArray *)x_names TargetValues:(NSMutableArray *)targetValues;


/**
 *  画饼状图
 *  @param x_names      x轴值的所有值名称
 *  @param targetValues 所有目标值
 */
-(void)drawPieChartViewWithX_Value_Names:(NSMutableArray *)x_names TargetValues:(NSMutableArray *)targetValues;


@end
