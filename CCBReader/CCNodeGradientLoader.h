#ifndef _CCB_CCNODEGRADIENT_LOADER_H_
#define _CCB_CCNODEGRADIENT_LOADER_H_

#include "CCNodeLoader.h"

NS_CC_EXT_BEGIN

/* Forward declaration. */
class CCBReader;
/**
 *  @js NA
 *  @lua NA
 */
class CCNodeGradientLoader : public CCNodeLoader {
    public:
        virtual ~CCNodeGradientLoader() {};
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CCNodeGradientLoader, loader);

    protected:
        //CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CCNodeGradient);

        virtual void onHandlePropTypeColor3(CCNode * pNode, CCNode * pParent, const char * pPropertyName, ccColor3B pCCColor3B, CCBReader * pCCBReader);
        virtual void onHandlePropTypeByte(CCNode * pNode, CCNode * pParent, const char * pPropertyName, unsigned char pByte, CCBReader * pCCBReader);
        virtual void onHandlePropTypePoint(CCNode * pNode, CCNode * pParent, const char * pPropertyName, CCPoint pPoint, CCBReader * pCCBReader);
        virtual void onHandlePropTypeBlendFunc(CCNode * pNode, CCNode * pParent, const char * pPropertyName, ccBlendFunc pCCBlendFunc, CCBReader * pCCBReader);
};

NS_CC_EXT_END

#endif
