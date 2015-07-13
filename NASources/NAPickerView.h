//
//  NAPickerView.h
//  NAPickerView
//
//  Created by iNghia on 8/4/13.
//  Copyright (c) 2013 nghialv. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NALabelCell.h"

@class NAPickerView;
@protocol NAPickerViewDelegate <NSObject>

typedef void (^NACellConfigureBlock)(id, id);
typedef void (^NACellHighlightConfigureBlock)(id);
typedef void (^NACellUnHighlightConfigureBlock)(id);

@optional
- (void)pickerView:(NAPickerView *)pickerView didSelectedAtIndex:(NSInteger)index;

@end

@interface NAPickerView : UIView

@property (weak, nonatomic) IBOutlet id delegate;
@property (assign, nonatomic) BOOL infiniteScrolling;
@property (assign, nonatomic) BOOL onSound;
@property (assign, nonatomic) BOOL showOverlay;


@property (copy, nonatomic) NACellConfigureBlock configureBlock;
@property (copy, nonatomic) NACellHighlightConfigureBlock highlightBlock;
@property (copy, nonatomic) NACellUnHighlightConfigureBlock unhighlightBlock;

// backgroud color
@property (assign, nonatomic) CGFloat borderWidth;
@property (strong, nonatomic) UIColor *borderColor;
@property (assign, nonatomic) CGFloat cornerRadius;

- (id)initWithFrame:(CGRect)frame
           andItems:(NSArray *)items
   andCellClassName:(NSString *)className
        andDelegate:(id)delegate;

- (id)initWithFrame:(CGRect)frame
           andItems:(NSArray *)items
        andDelegate:(id)delegate;

- (void)setIndex:(NSInteger)index;

// return the current selected Index
- (NSInteger)selectedIndex;
// refresh with Items
- (void)refreshWithItems:(NSArray*)items;
// return the current selected Value
- (id)selectedValue;

- (void)updateConfigurationInBlocks;

@end
