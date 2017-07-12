/*
 * Copyright 2017 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/*
 * This file was autogenerated from GrAlphaThresholdFragmentProcessor.fp; do not modify.
 */
#ifndef GrAlphaThresholdFragmentProcessor_DEFINED
#define GrAlphaThresholdFragmentProcessor_DEFINED
#include "SkTypes.h"
#if SK_SUPPORT_GPU

    #include "GrColorSpaceXform.h"
#include "GrFragmentProcessor.h"
#include "GrCoordTransform.h"
#include "effects/GrProxyMove.h"
class GrAlphaThresholdFragmentProcessor : public GrFragmentProcessor {
public:

    inline OptimizationFlags optFlags(float outerThreshold);
    sk_sp<GrColorSpaceXform> colorXform() const { return fColorXform; }
    float innerThreshold() const { return fInnerThreshold; }
    float outerThreshold() const { return fOuterThreshold; }

    static sk_sp<GrFragmentProcessor> Make(sk_sp<GrTextureProxy> image,
                                           sk_sp<GrColorSpaceXform> colorXform,
                                           sk_sp<GrTextureProxy> mask,
                                           float innerThreshold,
                                           float outerThreshold,
                                           const SkIRect& bounds) {
        return sk_sp<GrFragmentProcessor>(new GrAlphaThresholdFragmentProcessor(image,
                                                                                colorXform,
                                                                                mask,
                                                                                innerThreshold,
                                                                                outerThreshold,
                                                                                bounds));
    }
    const char* name() const override { return "AlphaThresholdFragmentProcessor"; }
private:
    GrAlphaThresholdFragmentProcessor(sk_sp<GrTextureProxy> image, sk_sp<GrColorSpaceXform> colorXform, sk_sp<GrTextureProxy> mask, float innerThreshold, float outerThreshold, 
    const SkIRect& bounds
)
    : INHERITED(kNone_OptimizationFlags)
    , 
    fImageCoordTransform(SkMatrix::I(), image.get()),
    fMaskCoordTransform(SkMatrix::MakeTrans(SkIntToScalar(-bounds.x()), SkIntToScalar(-bounds.y())),
                        mask.get())

    , fImage(std::move(image))
    , fColorXform(colorXform)
    , fMask(std::move(mask))
    , fInnerThreshold(innerThreshold)
    , fOuterThreshold(outerThreshold) {

    this->addCoordTransform(&fImageCoordTransform);
    this->addCoordTransform(&fMaskCoordTransform);
        this->addTextureSampler(&fImage);
        this->addTextureSampler(&fMask);
        this->initClassID<GrAlphaThresholdFragmentProcessor>();
    }
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&,GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST

    GrCoordTransform fImageCoordTransform;
    GrCoordTransform fMaskCoordTransform;
    TextureSampler fImage;
    sk_sp<GrColorSpaceXform> fColorXform;
    TextureSampler fMask;
    float fInnerThreshold;
    float fOuterThreshold;
    typedef GrFragmentProcessor INHERITED;
};
#endif
#endif
