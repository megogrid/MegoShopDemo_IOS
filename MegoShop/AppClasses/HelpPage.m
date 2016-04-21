//  HelpPage.m
//  Mego Shop Demo
//
//  Created by Mohammad on 2/24/16.
//  Copyright (c) 2016 unity. All rights reserved.
//

#import "HelpPage.h"


@interface HelpPage ()<UIScrollViewDelegate>
{
    UIView *mainView;
    UIScrollView *helpScrollView;
    CGFloat headingSize,subheadingSize,contentSize,totalHelpScrollHeight;;
    NSMutableArray *typesNameArray,*contentArray;
}
@end

@implementation HelpPage

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self backGroundUiPart];
    [self  fontSizeCalculation];
    [self headerSection];
    [self  descriptionOfHelpController];
}

#pragma mark UI Part
-(void)backGroundUiPart
{
    mainView=[[UIView alloc]initWithFrame:CGRectMake(0, 64, self.view.frame.size.width, self.view.frame.size.height-64)];
    mainView.backgroundColor=[UIColor whiteColor];
    [self.view addSubview:mainView];
    helpScrollView=[[UIScrollView alloc]initWithFrame:CGRectMake(0,0,mainView.frame.size.width,mainView.frame.size.height)];
    [helpScrollView setBackgroundColor:[UIColor clearColor]];
    helpScrollView.delegate=self;
    self.automaticallyAdjustsScrollViewInsets = NO;
    [mainView addSubview:helpScrollView];
    helpScrollView.userInteractionEnabled=TRUE;
    helpScrollView.scrollEnabled=YES;
    helpScrollView.showsVerticalScrollIndicator=TRUE;
    [helpScrollView setContentSize: CGSizeMake(helpScrollView.bounds.size.width,mainView.frame.size.height)];
}

-(void)headerSection
{
    UIView*headerView = [[UIView alloc]initWithFrame:CGRectMake(0, 0,self.view.frame.size.width,64)];
    [headerView setBackgroundColor:[UIColor colorWithRed:79/255.0f green:109/255.0f blue:147/255.0f alpha:1]];
    [self.view addSubview:headerView];
    
    UIView *navView=[[UIView alloc]initWithFrame:CGRectMake(0, 19, self.view.frame.size.width,45)];
    [headerView addSubview:navView];
    
    UIButton *backButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [backButton setFrame:CGRectMake(15,12,17,18)];
    [backButton addTarget:self action:@selector(navBackButton)forControlEvents:UIControlEventTouchUpInside];
    [backButton setBackgroundImage:[UIImage imageNamed:@"back_icn.png"] forState:UIControlStateNormal];
    [backButton setBackgroundImage:[UIImage imageNamed:@"back_icn.png"] forState:UIControlStateSelected];
    [navView addSubview :backButton];
    
    
    CGSize yourLabelSize = [@"Help" sizeWithAttributes:@{NSFontAttributeName : [UIFont fontWithName:@"HelveticaNeue" size:headingSize]}];
    
    UILabel *title = [[UILabel alloc]initWithFrame:CGRectMake((navView.frame.size.width-yourLabelSize.width)/2,0 ,yourLabelSize.width+10, 45) ];
    title.text = @"Help";
    title.textAlignment=NSTextAlignmentCenter;
    title.textColor = [UIColor whiteColor];
    title.font = [UIFont boldSystemFontOfSize:headingSize];
    [navView addSubview:title];
}

-(void)fontSizeCalculation
{
    if([[UIScreen mainScreen]bounds].size.height<=568) // iPhone4S,iPhone5
    {
        headingSize=20;
        subheadingSize=14;
        contentSize=12.9;
    }
    else //iPhone6
    {
        headingSize=22;
        subheadingSize=14;
        contentSize=14;
    }
}

#pragma mark Content Part

-(void)descriptionOfHelpController
{
    typesNameArray=[[NSMutableArray alloc]initWithObjects:@"Mego Shop",
                    @"Permanent:\nThis purchase type applied on-Take photo \n& Apply images",
                    @"Partial:\nThis purchase type applied on-Choose Image \n from Gallery",
                    @"Subscription:\nThis purchase type applied on-Share under\n navigation drawer",
                    nil];
    
    contentArray=[[NSMutableArray alloc]initWithObjects:@"Mego Shop is one of our MegoGrid module which helps you to unlock the premium features of your app using virtual currency \n \nIt manages three types of purchase e.g.  permanent (one time), partial OR subscription. Below are their brief explanation",
                  
                  @"This  purchase helps your app user to unlock the permium feature for ever. That means once they unlock any premium feature of your application user will able to use it forever",
                  
                  @"This purchase helps your app user to unlock the premium feature for a specific time period like for a week, month, quarterly etc. Once the provided time period is over that feature will locked again. In this case user have to again unlock it",
                  
                  @"This purchase helps your app user to unlock the premium feature on a subscription based just like we subscribe news letter and play regular amount of subscription.if user don't want to continue with subscription he has to cancel it by sending a cancellation request",
                  
                  
                  nil];
    
    
    for(int i=0;i<[typesNameArray count];i++)
    {
        [self  detailForTypes:[typesNameArray objectAtIndex:i]:[contentArray objectAtIndex:i]];
    }
}

-(void)detailForTypes:(NSString*)typesName :(NSString*)content
{
    float myTextHeight = 0;
    totalHelpScrollHeight=totalHelpScrollHeight+26;
    
    CGSize yourLabelSize = [typesName sizeWithAttributes:@{NSFontAttributeName:[UIFont boldSystemFontOfSize :subheadingSize]}];
    
    UILabel *contentType = [[UILabel alloc]initWithFrame:CGRectMake(10,totalHelpScrollHeight,yourLabelSize.width+20,yourLabelSize.height)];
    contentType.text=[typesName stringByAppendingString:@" "];
    contentType.font=[UIFont boldSystemFontOfSize :subheadingSize];
    contentType.textColor = [UIColor colorWithRed:75/255.0 green:103/255.0 blue:143/255.0 alpha:1];
    contentType.textAlignment = NSTextAlignmentLeft;
    [helpScrollView addSubview:contentType];
    contentType.numberOfLines=0;
    totalHelpScrollHeight=totalHelpScrollHeight+yourLabelSize.height+10;
    
    
    UILabel *contentLabel=[[UILabel alloc]initWithFrame:CGRectMake(10,totalHelpScrollHeight,helpScrollView.frame.size.width-20,myTextHeight)];
    CGSize maximumSize = CGSizeMake(self.view.frame.size.width-20,CGFLOAT_MAX);
    UIFont *myFont = [UIFont fontWithName:@"Arial" size:contentSize];
    
    CGRect myTextRect = [content boundingRectWithSize:maximumSize
                                              options:NSStringDrawingUsesLineFragmentOrigin
                                           attributes:@{NSFontAttributeName:myFont}
                                              context:nil];
    
    CGSize myTextSize = myTextRect.size;
    CGRect newFrame = contentLabel.frame;
    newFrame.size.height = myTextSize.height;
    contentLabel.frame = newFrame;
    contentLabel.numberOfLines=0;
    contentLabel.font = myFont;
    contentLabel.textAlignment = NSTextAlignmentLeft;
    myTextHeight = myTextSize.height;
    contentLabel.text = content;
    contentLabel.textColor = [UIColor grayColor];
    [helpScrollView addSubview:contentLabel];
    totalHelpScrollHeight=contentLabel.frame.origin.y+contentLabel.frame.size.height;
    
    
    if(helpScrollView.frame.size.height<totalHelpScrollHeight)
    {
        [helpScrollView setContentSize: CGSizeMake(helpScrollView.bounds.size.width,totalHelpScrollHeight+20)];
    }
}

-(void)navBackButton{
    [self.navigationController popViewControllerAnimated:YES];
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    
}


@end
