#include "CCControlLoader.h"


NS_CC_EXT_BEGIN

#define PROPERTY_ENABLED "enabled"
#define PROPERTY_SELECTED "selected"
#define PROPERTY_CCCONTROL "ccControl"
#define PROPERTY_MAXSIZE "maxSize"

void CCControlLoader::onHandlePropTypeCheck(CCNode * pNode, CCNode * pParent, const char * pPropertyName, bool pCheck, CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_ENABLED) == 0) {
        ((CCControl *)pNode)->setEnabled(pCheck);
    } else if(strcmp(pPropertyName, PROPERTY_SELECTED) == 0) {
        ((CCControl *)pNode)->setSelected(pCheck);
    } else {
        CCNodeLoader::onHandlePropTypeCheck(pNode, pParent, pPropertyName, pCheck, pCCBReader);
    }
}

void CCControlLoader::onHandlePropTypeBlockCCControl(CCNode * pNode, CCNode * pParent, const char * pPropertyName, BlockCCControlData * pBlockCCControlData, CCBReader * pCCBReader) {
    if(strcmp(pPropertyName, PROPERTY_CCCONTROL) == 0) {
        ((CCControl *)pNode)->addTargetWithActionForControlEvents(pBlockCCControlData->mTarget, pBlockCCControlData->mSELCCControlHandler, pBlockCCControlData->mControlEvents);
    } else {
        CCNodeLoader::onHandlePropTypeBlockCCControl(pNode, pParent, pPropertyName, pBlockCCControlData, pCCBReader);
    }
}


void CCControlLoader::onHandlePropTypeSize(CCNode * pNode, CCNode * pParent, const char * pPropertyName, CCSize pSize, CCBReader * pCCBReader)
{
	if( strcmp( pPropertyName, PROPERTY_MAXSIZE ) == 0 )
	{
		// How can I handle property of max size?
	}
	else
		CCNodeLoader::onHandlePropTypeSize( pNode, pParent, pPropertyName, pSize, pCCBReader );
}

NS_CC_EXT_END