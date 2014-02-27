#include "CCControlButtonLoader.h"


NS_CC_EXT_BEGIN;

#define PROPERTY_ZOOMONTOUCHDOWN "zoomOnTouchDown"

#define PROPERTY_FONT_NAME "fontName"
#define PROPERTY_FONT_SIZE "fontSize"
#define PROPERTY_FONT_COLOR "fontColor"

#define PROPERTY_OUTLINE_COLOR "outlineColor"
#define PROPERTY_OUTLINE_WIDTH "outlineWidth"

#define PROPERTY_SHADOW_COLOR "shadowColor"
#define PROPERTY_SHADOW_BLUR_RADIUS "shadowBlurRadius"
#define PROPERTY_SHADOW_OFFSET "shadowOffset"

#define PROPERTY_PADDING_HORIZONTAL "horizontalPadding"
#define PROPERTY_PADDING_VERTICAL "verticalPadding"

#define PROPERTY_TITLE_NORMAL "title|1"
#define PROPERTY_TITLE_HIGHLIGHTED "title|2"
#define PROPERTY_TITLE_DISABLED "title|3"

#define PROPERTY_TITLECOLOR_NORMAL "titleColor|1"
#define PROPERTY_TITLECOLOR_HIGHLIGHTED "titleColor|2"
#define PROPERTY_TITLECOLOR_DISABLED "titleColor|3"

#define PROPERTY_TITLETTF_NORMAL "titleTTF|1"
#define PROPERTY_TITLETTF_HIGHLIGHTED "titleTTF|2"
#define PROPERTY_TITLETTF_DISABLED "titleTTF|3"

#define PROPERTY_TITLETTFSIZE_NORMAL "titleTTFSize|1"
#define PROPERTY_TITLETTFSIZE_HIGHLIGHTED "titleTTFSize|2"
#define PROPERTY_TITLETTFSIZE_DISABLED "titleTTFSize|3"

#define PROPERTY_LABELANCHORPOINT "labelAnchorPoint"
#define PROPERTY_PREFERREDSIZE "preferredSize" // TODO Should be "preferredSize". This is a typo in cocos2d-iphone, cocos2d-x and CocosBuilder!

#define PROPERTY_BACKGROUNDSPRITEFRAME_NORMAL "backgroundSpriteFrame|Normal"
#define PROPERTY_BACKGROUNDSPRITEFRAME_HIGHLIGHTED "backgroundSpriteFrame|Highlighted"
#define PROPERTY_BACKGROUNDSPRITEFRAME_DISABLED "backgroundSpriteFrame|Disabled"
#define PROPERTY_BACKGROUNDSPRITEFRAME_SELECTED "backgroundSpriteFrame|Selected"

#define PROPERTY_LABELCOLOR_HIGHLIGHTED "labelColor|Highlighted"

#define PROPERTY_BLOCK "block"


void CCControlButtonLoader::onHandlePropTypePosition(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCPoint pPosition, CCBReader * pCCBReader) {

	CCControlButton *button = dynamic_cast< CCControlButton* >( pNode );
	if( button == NULL )
	{
		ASSERT_FAIL_UNEXPECTED_PROPERTY( "onHandlePropTypePosition - pNode is not CCControlButton" );
		return;
	}

	CCLabelTTF *label = dynamic_cast< CCLabelTTF* >( button->getTitleLabel() );

    if(strcmp(pPropertyName, PROPERTY_SHADOW_OFFSET) == 0) 
	{
        ccFontDefinition *tDef = label->getTextDefinition();
		tDef->m_shadow.m_shadowOffset = pPosition;
		label->setTextDefinition( tDef );
    } 
	else 
	{
		CCNodeLoader::onHandlePropTypePosition( pNode, pParent, pPropertyName, pPosition, pCCBReader );
    }
}

void CCControlButtonLoader::onHandlePropTypeCheck(CCNode * pNode, CCNode * pParent, const char * pPropertyName, bool pCheck, CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_ZOOMONTOUCHDOWN) == 0) {
        ((CCControlButton *)pNode)->setZoomOnTouchDown(pCheck);
    } else {
        CCControlLoader::onHandlePropTypeCheck(pNode, pParent, pPropertyName, pCheck, pCCBReader);
    }
}

void CCControlButtonLoader::onHandlePropTypeString(CCNode * pNode, CCNode * pParent, const char * pPropertyName, const char * pString, CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_TITLE_NORMAL) == 0) {
        ((CCControlButton *)pNode)->setTitleForState(CCString::create(pString), CCControlStateNormal);
    } else if(strcmp(pPropertyName, PROPERTY_TITLE_HIGHLIGHTED) == 0) {
        ((CCControlButton *)pNode)->setTitleForState(CCString::create(pString), CCControlStateHighlighted);
    } else if(strcmp(pPropertyName, PROPERTY_TITLE_DISABLED) == 0) {
        ((CCControlButton *)pNode)->setTitleForState(CCString::create(pString), CCControlStateDisabled);
    } else {
        CCControlLoader::onHandlePropTypeString(pNode, pParent, pPropertyName, pString, pCCBReader);
    }
}

void CCControlButtonLoader::onHandlePropTypeFontTTF(CCNode * pNode, CCNode * pParent, const char * pPropertyName, const char * pFontTTF, CCBReader * pCCBReader) {
	if( strcmp( pPropertyName, PROPERTY_FONT_NAME ) == 0 )
	{
		CCControlButton *button = dynamic_cast< CCControlButton* >( pNode );
		if( button )
		{
			CCLabelTTF *label = dynamic_cast< CCLabelTTF* >( button->getTitleLabel() );
			label->setFontName( pFontTTF );
		}
	}
    else if(strcmp(pPropertyName, PROPERTY_TITLETTF_NORMAL) == 0) {
        ((CCControlButton *)pNode)->setTitleTTFForState(pFontTTF, CCControlStateNormal);
    } else if(strcmp(pPropertyName, PROPERTY_TITLETTF_HIGHLIGHTED) == 0) {
        ((CCControlButton *)pNode)->setTitleTTFForState(pFontTTF, CCControlStateHighlighted);
    } else if(strcmp(pPropertyName, PROPERTY_TITLETTF_DISABLED) == 0) {
        ((CCControlButton *)pNode)->setTitleTTFForState(pFontTTF, CCControlStateDisabled);
    } else {
        CCControlLoader::onHandlePropTypeFontTTF(pNode, pParent, pPropertyName, pFontTTF, pCCBReader);
    }
}

void CCControlButtonLoader::onHandlePropTypeFloatScale(CCNode * pNode, CCNode * pParent, const char * pPropertyName, float pFloatScale, CCBReader * pCCBReader) {

	CCControlButton *button = dynamic_cast< CCControlButton* >( pNode );
	if( button == NULL )
	{
		ASSERT_FAIL_UNEXPECTED_PROPERTY( "onHandlePropTypeFloatScale - pNode is not CCControlButton" );
		return;
	}

	CCLabelTTF *label = dynamic_cast< CCLabelTTF* >( button->getTitleLabel() );

	if( strcmp( pPropertyName, PROPERTY_FONT_SIZE ) == 0 )
	{
		label = dynamic_cast< CCLabelTTF* >( button->getTitleLabel() );
		label->setFontSize( pFloatScale );
	}
	else if( strcmp( pPropertyName, PROPERTY_OUTLINE_WIDTH ) == 0 ) 
	{
		ccFontDefinition *tDef = label->getTextDefinition();
		tDef->m_stroke.m_strokeSize = pFloatScale;
		label->setTextDefinition( tDef );
	}
	else if( strcmp( pPropertyName, PROPERTY_SHADOW_BLUR_RADIUS ) == 0) 
	{
		ccFontDefinition *tDef = label->getTextDefinition();
		tDef->m_shadow.m_shadowBlur = pFloatScale;
		label->setTextDefinition( tDef );
	}
	else if( strcmp( pPropertyName, PROPERTY_PADDING_HORIZONTAL ) == 0 )
	{
		// What is horizontalPadding?
	}
	else if( strcmp( pPropertyName, PROPERTY_PADDING_VERTICAL ) == 0 )
	{
		// What is verticalPadding?
	}
    else if(strcmp(pPropertyName, PROPERTY_TITLETTFSIZE_NORMAL) == 0) {
        ((CCControlButton *)pNode)->setTitleTTFSizeForState(pFloatScale, CCControlStateNormal);
    } else if(strcmp(pPropertyName, PROPERTY_TITLETTFSIZE_HIGHLIGHTED) == 0) {
        ((CCControlButton *)pNode)->setTitleTTFSizeForState(pFloatScale, CCControlStateHighlighted);
    } else if(strcmp(pPropertyName, PROPERTY_TITLETTFSIZE_DISABLED) == 0) {
        ((CCControlButton *)pNode)->setTitleTTFSizeForState(pFloatScale, CCControlStateDisabled);
    } else {
        CCControlLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pFloatScale, pCCBReader);
    }
}

void CCControlButtonLoader::onHandlePropTypePoint(CCNode * pNode, CCNode * pParent, const char * pPropertyName, CCPoint pPoint, CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_LABELANCHORPOINT) == 0) {
        ((CCControlButton *)pNode)->setLabelAnchorPoint(pPoint);
    } else {
        CCControlLoader::onHandlePropTypePoint(pNode, pParent, pPropertyName, pPoint, pCCBReader);
    }
}

void CCControlButtonLoader::onHandlePropTypeSize(CCNode * pNode, CCNode * pParent, const char * pPropertyName, CCSize pSize, CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_PREFERREDSIZE) == 0) {
        ((CCControlButton *)pNode)->setPreferredSize(pSize);
    } else {
        CCControlLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, pCCBReader);
    }
}

void CCControlButtonLoader::onHandlePropTypeSpriteFrame(CCNode * pNode, CCNode * pParent, const char * pPropertyName, CCSpriteFrame * pCCSpriteFrame, CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_NORMAL) == 0) {
        if(pCCSpriteFrame != NULL) {
            ((CCControlButton *)pNode)->setBackgroundSpriteFrameForState(pCCSpriteFrame, CCControlStateNormal);
        }
    } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_HIGHLIGHTED) == 0) {
        if(pCCSpriteFrame != NULL) {
            ((CCControlButton *)pNode)->setBackgroundSpriteFrameForState(pCCSpriteFrame, CCControlStateHighlighted);
        }
    } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_DISABLED) == 0) {
        if(pCCSpriteFrame != NULL) {
            ((CCControlButton *)pNode)->setBackgroundSpriteFrameForState(pCCSpriteFrame, CCControlStateDisabled);
        }
    } else if(strcmp(pPropertyName, PROPERTY_BACKGROUNDSPRITEFRAME_SELECTED) == 0) {
        if(pCCSpriteFrame != NULL) {
			((CCControlButton *)pNode)->setBackgroundSpriteFrameForState(pCCSpriteFrame, CCControlStateSelected);
        }
    } else {
        CCControlLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pCCSpriteFrame, pCCBReader);
    }
}

void CCControlButtonLoader::onHandlePropTypeColor3(CCNode * pNode, CCNode * pParent, const char * pPropertyName, ccColor3B pCCColor3B, CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_TITLECOLOR_NORMAL) == 0) {
        ((CCControlButton *)pNode)->setTitleColorForState(pCCColor3B, CCControlStateNormal);
    } else if(strcmp(pPropertyName, PROPERTY_TITLECOLOR_HIGHLIGHTED) == 0) {
        ((CCControlButton *)pNode)->setTitleColorForState(pCCColor3B, CCControlStateHighlighted);
    } else if(strcmp(pPropertyName, PROPERTY_TITLECOLOR_DISABLED) == 0) {
        ((CCControlButton *)pNode)->setTitleColorForState(pCCColor3B, CCControlStateDisabled);
    } else {
        CCControlLoader::onHandlePropTypeColor3(pNode, pParent, pPropertyName, pCCColor3B, pCCBReader);
    }
}


void CCControlButtonLoader::onHandlePropTypeColor4(CCNode * pNode, CCNode * pParent, const char* pPropertyName, ccColor4F pCCColor4F, CCBReader * pCCBReader)
{
	unsigned char r = pCCColor4F.r * 255;
	unsigned char g = pCCColor4F.g * 255;
	unsigned char b = pCCColor4F.b * 255;
	unsigned char a = pCCColor4F.a * 255;
	ccColor3B color = { r, g, b };

	CCControlButton *button = dynamic_cast< CCControlButton* >( pNode );
	if( button == NULL )
	{
		ASSERT_FAIL_UNEXPECTED_PROPERTY( "onHandlePropTypeColor4 - pNode is not CCControlButton" );
		return;
	}

	CCLabelTTF *label = dynamic_cast< CCLabelTTF* >( button->getTitleLabel() );

	if( strcmp( pPropertyName, PROPERTY_FONT_COLOR ) == 0 )
	{
		label = dynamic_cast< CCLabelTTF* >( button->getTitleLabel() );
		label->setFontFillColor( color );
	}
	else if( strcmp( pPropertyName, PROPERTY_OUTLINE_COLOR ) == 0 )
	{
		ccFontDefinition *tDef = label->getTextDefinition();
		tDef->m_stroke.m_strokeColor = ccc3( r, g, b );
		label->setTextDefinition( tDef );
	}
	else if( strcmp( pPropertyName, PROPERTY_SHADOW_COLOR ) == 0 )
	{
		//
		// cocos2dx CCLabelTTF is not support shadow color, yet.
		//
		/*ccFontDefinition *tDef = label->getTextDefinition();
		label->setTextDefinition( tDef );*/
	}
	else if( strcmp( pPropertyName, PROPERTY_LABELCOLOR_HIGHLIGHTED ) == 0 ) 
	{
		button->setTitleColorForState(color, CCControlStateHighlighted);
    } 
	else 
	{
        CCControlLoader::onHandlePropTypeColor3(pNode, pParent, pPropertyName, color, pCCBReader);
    }
}


void CCControlButtonLoader::onHandlePropTypeBlock(CCNode * pNode, CCNode * pParent, const char* pPropertyName, BlockData * pBlockData, CCBReader * pCCBReader)
{
	CCNodeLoader::onHandlePropTypeBlock( pNode, pParent, pPropertyName, pBlockData, pCCBReader );
}


void CCControlButtonLoader::onHandlePropTypeBlockCCControl(CCNode * pNode, CCNode * pParent, const char * pPropertyName, BlockCCControlData * pBlockCCControlData, CCBReader * pCCBReader)
{
	if( strcmp( pPropertyName, PROPERTY_BLOCK ) == 0 )
	{
		((CCControl *)pNode)->addTargetWithActionForControlEvents(pBlockCCControlData->mTarget, pBlockCCControlData->mSELCCControlHandler, pBlockCCControlData->mControlEvents);
	}
	else
	{
		CCNodeLoader::onHandlePropTypeBlockCCControl( pNode, pParent, pPropertyName, pBlockCCControlData, pCCBReader );
	}
}



NS_CC_EXT_END;