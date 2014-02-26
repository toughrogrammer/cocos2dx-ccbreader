
#include "CCLabelTTFLoader.h"


#define PROPERTY_COLOR "color"
#define PROPERTY_OPACITY "opacity"
#define PROPERTY_BLENDFUNC "blendFunc"
#define PROPERTY_FONTNAME "fontName"
#define PROPERTY_FONTSIZE "fontSize"
#define PROPERTY_FONT_COLOR "fontColor"

#define PROPERTY_OUTLINE_COLOR "outlineColor"
#define PROPERTY_OUTLINE_WIDTH "outlineWidth"

#define PROPERTY_SHADOW_COLOR "shadowColor"
#define PROPERTY_SHADOW_BLUR_RADIUS "shadowBlurRadius"
#define PROPERTY_SHADOW_OFFSET "shadowOffset"

#define PROPERTY_HORIZONTALALIGNMENT "horizontalAlignment"
#define PROPERTY_VERTICALALIGNMENT "verticalAlignment"
#define PROPERTY_STRING "string"
#define PROPERTY_DIMENSIONS "dimensions"

NS_CC_EXT_BEGIN


void CCLabelTTFLoader::onHandlePropTypePosition(CCNode * pNode, CCNode * pParent, const char* pPropertyName, CCPoint pPosition, CCBReader * pCCBReader) 
{
	if(strcmp(pPropertyName, PROPERTY_SHADOW_OFFSET) == 0) 
	{
		CCLabelTTF *label = dynamic_cast< CCLabelTTF* >( pNode );
        ccFontDefinition *tDef = label->getTextDefinition();
		tDef->m_shadow.m_shadowOffset = pPosition;
		label->setTextDefinition( tDef );
    } 
	else 
	{
        CCNodeLoader::onHandlePropTypePosition( pNode, pParent, pPropertyName, pPosition, pCCBReader );
    }
}

void CCLabelTTFLoader::onHandlePropTypeColor4(CCNode * pNode, CCNode * pParent, const char* pPropertyName, ccColor4F pCCColor4F, CCBReader * pCCBReader )
{
	CCLabelTTF *label = dynamic_cast< CCLabelTTF* >( pNode );
	if( label != NULL )
	{
		unsigned char r = pCCColor4F.r * 255;
		unsigned char g = pCCColor4F.g * 255;
		unsigned char b = pCCColor4F.b * 255;
		unsigned char a = pCCColor4F.a * 255;

		if( strcmp( pPropertyName, PROPERTY_FONT_COLOR ) == 0 )
		{
			label->setFontFillColor( ccc3( r, g, b ) );
			label->setOpacity( a );
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
		else
		{
			CCNodeLoader::onHandlePropTypeColor4( pNode, pParent, pPropertyName, pCCColor4F, pCCBReader );
		}
	}
	else
	{
		CCNodeLoader::onHandlePropTypeColor4( pNode, pParent, pPropertyName, pCCColor4F, pCCBReader );
	}
}

void CCLabelTTFLoader::onHandlePropTypeColor3(CCNode * pNode, CCNode * pParent, const char * pPropertyName, ccColor3B pCCColor3B, CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_COLOR) == 0) {
        ((CCLabelTTF *)pNode)->setColor(pCCColor3B);
    } else {
        CCNodeLoader::onHandlePropTypeColor3(pNode, pParent, pPropertyName, pCCColor3B, pCCBReader);
    }
}

void CCLabelTTFLoader::onHandlePropTypeByte(CCNode * pNode, CCNode * pParent, const char * pPropertyName, unsigned char pByte, CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_OPACITY) == 0) {
        ((CCLabelTTF *)pNode)->setOpacity(pByte);
    } else {
        CCNodeLoader::onHandlePropTypeByte(pNode, pParent, pPropertyName, pByte, pCCBReader);
    }
}

void CCLabelTTFLoader::onHandlePropTypeBlendFunc(CCNode * pNode, CCNode * pParent, const char * pPropertyName, ccBlendFunc pCCBlendFunc, CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_BLENDFUNC) == 0) {
        ((CCLabelTTF *)pNode)->setBlendFunc(pCCBlendFunc);
    } else {
        CCNodeLoader::onHandlePropTypeBlendFunc(pNode, pParent, pPropertyName, pCCBlendFunc, pCCBReader);
    }
}

void CCLabelTTFLoader::onHandlePropTypeFontTTF(CCNode * pNode, CCNode * pParent, const char * pPropertyName, const char * pFontTTF, CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_FONTNAME) == 0) {
        ((CCLabelTTF *)pNode)->setFontName(pFontTTF);
    } else {
        CCNodeLoader::onHandlePropTypeFontTTF(pNode, pParent, pPropertyName, pFontTTF, pCCBReader);
    }
}

void CCLabelTTFLoader::onHandlePropTypeText(CCNode * pNode, CCNode * pParent, const char * pPropertyName, const char * pText, CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_STRING) == 0) {
        ((CCLabelTTF *)pNode)->setString(pText);
    } else {
        CCNodeLoader::onHandlePropTypeText(pNode, pParent, pPropertyName, pText, pCCBReader);
    }
}

void CCLabelTTFLoader::onHandlePropTypeFloatScale(CCNode * pNode, CCNode * pParent, const char * pPropertyName, float pFloatScale, CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_FONTSIZE) == 0) {
        ((CCLabelTTF *)pNode)->setFontSize(pFloatScale);
    } 
	else if(strcmp(pPropertyName, PROPERTY_OUTLINE_WIDTH) == 0) {
		CCLabelTTF *label = dynamic_cast< CCLabelTTF* >( pNode );
		ccFontDefinition *tDef = label->getTextDefinition();
		tDef->m_stroke.m_strokeSize = pFloatScale;
		label->setTextDefinition( tDef );
	} else if(strcmp(pPropertyName, PROPERTY_SHADOW_BLUR_RADIUS ) == 0) {
		CCLabelTTF *label = dynamic_cast< CCLabelTTF* >( pNode );
		ccFontDefinition *tDef = label->getTextDefinition();
		tDef->m_shadow.m_shadowBlur = pFloatScale;
		label->setTextDefinition( tDef );
	} else {
        CCNodeLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pFloatScale, pCCBReader);
    }
}

void CCLabelTTFLoader::onHandlePropTypeIntegerLabeled(CCNode * pNode, CCNode * pParent, const char * pPropertyName, int pIntegerLabeled, CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_HORIZONTALALIGNMENT) == 0) {
        ((CCLabelTTF *)pNode)->setHorizontalAlignment(CCTextAlignment(pIntegerLabeled));
    } else if(strcmp(pPropertyName, PROPERTY_VERTICALALIGNMENT) == 0) {
        ((CCLabelTTF *)pNode)->setVerticalAlignment(CCVerticalTextAlignment(pIntegerLabeled));
    } else {
        CCNodeLoader::onHandlePropTypeFloatScale(pNode, pParent, pPropertyName, pIntegerLabeled, pCCBReader);
    }
}

void CCLabelTTFLoader::onHandlePropTypeSize(CCNode * pNode, CCNode * pParent, const char * pPropertyName, CCSize pSize, CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_DIMENSIONS) == 0) {
        ((CCLabelTTF *)pNode)->setDimensions(pSize);
    } else {
        CCNodeLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, pCCBReader);
    }
}

NS_CC_EXT_END