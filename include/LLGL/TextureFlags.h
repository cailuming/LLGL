/*
 * TextureFlags.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_TEXTURE_FLAGS_H__
#define __LLGL_TEXTURE_FLAGS_H__


#include "Export.h"
#include "RenderSystemFlags.h"
#include <Gauss/Vector3.h>
#include <cstddef>


namespace LLGL
{


/* ----- Enumerations ----- */

//! Texture type enumeration.
enum class TextureType
{
    Undefined,          //!< Initial value of a Texture object.
    Texture1D,          //!< 1-Dimensional texture.
    Texture2D,          //!< 2-Dimensional texture.
    Texture3D,          //!< 3-Dimensional texture.
    TextureCube,        //!< Cube texture.
    Texture1DArray,     //!< 1-Dimensional array texture.
    Texture2DArray,     //!< 2-Dimensional array texture.
    TextureCubeArray,   //!< Cube array texture.
};

/**
\brief Hardware texture format enumeration.
\note All integral 32-bit formats are un-normalized!
*/
enum class TextureFormat
{
    /* --- Base formats --- */
    DepthComponent, //!< Base format: depth component.
    DepthStencil,   //!< Base format: depth- and stencil components.
    R,              //!< Base format: red component.
    RG,             //!< Base format: red and green components.
    RGB,            //!< Base format: red, green and blue components.
    RGBA,           //!< Base format: red, green, blue and alpha components.

    /* --- Sized formats --- */
    R8,             //!< Sized format: red 8-bit normalized unsigned integer component.
    R8Sgn,          //!< Sized format: red 8-bit normalized signed integer component.

    R16,            //!< Sized format: red 16-bit normalized unsigned interger component.
    R16Sgn,         //!< Sized format: red 16-bit normalized signed interger component.
    R16Float,       //!< Sized format: red 16-bit floating point component.

    R32UInt,        //!< Sized format: red 32-bit un-normalized unsigned interger component.
    R32SInt,        //!< Sized format: red 32-bit un-normalized signed interger component.
    R32Float,       //!< Sized format: red 32-bit floating point component.

    RG8,            //!< Sized format: red, green 8-bit normalized unsigned integer components.
    RG8Sgn,         //!< Sized format: red, green 8-bit normalized signed integer components.

    RG16,           //!< Sized format: red, green 16-bit normalized unsigned interger components.
    RG16Sgn,        //!< Sized format: red, green 16-bit normalized signed interger components.
    RG16Float,      //!< Sized format: red, green 16-bit floating point components.

    RG32UInt,       //!< Sized format: red, green 32-bit un-normalized unsigned interger components.
    RG32SInt,       //!< Sized format: red, green 32-bit un-normalized signed interger components.
    RG32Float,      //!< Sized format: red, green 32-bit floating point components.

    RGB8,           //!< Sized format: red, green, blue 8-bit normalized unsigned integer components.
    RGB8Sgn,        //!< Sized format: red, green, blue 8-bit normalized signed integer components.

    RGB16,          //!< Sized format: red, green, blue 16-bit normalized unsigned interger components.
    RGB16Sgn,       //!< Sized format: red, green, blue 16-bit normalized signed interger components.
    RGB16Float,     //!< Sized format: red, green, blue 16-bit floating point components.

    RGB32UInt,      //!< Sized format: red, green, blue 32-bit un-normalized unsigned interger components.
    RGB32SInt,      //!< Sized format: red, green, blue 32-bit un-normalized signed interger components.
    RGB32Float,     //!< Sized format: red, green, blue 32-bit floating point components.

    RGBA8,          //!< Sized format: red, green, blue, alpha 8-bit normalized unsigned integer components.
    RGBA8Sgn,       //!< Sized format: red, green, blue, alpha 8-bit normalized signed integer components.

    RGBA16,         //!< Sized format: red, green, blue, alpha 16-bit normalized unsigned interger components.
    RGBA16Sgn,      //!< Sized format: red, green, blue, alpha 16-bit normalized signed interger components.
    RGBA16Float,    //!< Sized format: red, green, blue, alpha 16-bit floating point components.

    RGBA32UInt,     //!< Sized format: red, green, blue, alpha 32-bit un-normalized unsigned interger components.
    RGBA32SInt,     //!< Sized format: red, green, blue, alpha 32-bit un-normalized signed interger components.
    RGBA32Float,    //!< Sized format: red, green, blue, alpha 32-bit floating point components.

    /* --- Compressed formats --- */
    RGB_DXT1,       //!< Compressed format: RGB S3TC DXT1.
    RGBA_DXT1,      //!< Compressed format: RGBA S3TC DXT1.
    RGBA_DXT3,      //!< Compressed format: RGBA S3TC DXT3.
    RGBA_DXT5,      //!< Compressed format: RGBA S3TC DXT5.
};

//! Color format used to write texture data.
enum class ColorFormat
{
    Gray,           //!< Single color component: Gray or rather brightness.
    GrayAlpha,      //!< Two color components: Gray, Alpha.
    RGB,            //!< Three color components: Red, Green, Blue.
    BGR,            //!< Three color components: Blue, Green, Red.
    RGBA,           //!< Four color components: Red, Green, Blue, Alpha.
    BGRA,           //!< Four color components: Blue, Green, Red, Alpha.
    Depth,          //!< Single color component used as depth component.
    DepthStencil,   //!< Pair of depth and stencil component.
};

//! Axis direction (also used for texture cube face).
enum class AxisDirection
{
    XPos = 0,   //!< X+ direction.
    XNeg,       //!< X- direction.
    YPos,       //!< Y+ direction.
    YNeg,       //!< Y- direction.
    ZPos,       //!< Z+ direction.
    ZNeg,       //!< Z- direction.
};


/* ----- Structures ----- */

//! Texture data descriptor structure.
struct LLGL_EXPORT ImageDataDescriptor
{
    ImageDataDescriptor() = default;
    ImageDataDescriptor(ColorFormat dataFormat, DataType dataType, const void* data) :
        dataFormat  ( dataFormat ),
        dataType    ( dataType   ),
        data        ( data       )
    {
    }

    ColorFormat dataFormat  = ColorFormat::Gray;
    DataType    dataType    = DataType::UByte;
    const void* data        = nullptr;
};

//! Texture descriptor union.
union TextureDescriptor
{
    TextureType type;

    struct Texture1DDescriptor
    {
        TextureType     type;
        int             width;
        unsigned int    layers;
    }
    texture1DDesc;

    struct Texture2DDescriptor
    {
        TextureType     type;
        int             width;
        int             height;
        unsigned int    layers;
    }
    texture2DDesc;

    struct Texture3DDescriptor
    {
        TextureType     type;
        int             width;
        int             height;
        int             depth;
    }
    texture3DDesc;

    struct TextureCubeDescriptor
    {
        TextureType     type;
        int             width;
        int             height;
        unsigned int    layers;
    }
    textureCubeDesc;
};


/* ----- Functions ----- */

//! Returns the size (in number of components) of the specified color format.
LLGL_EXPORT std::size_t ColorFormatSize(const ColorFormat colorFormat);

/**
\brief Returns the number of MIP-map levels for a texture with the specified size.
\return 1 + floor(log2(max{ x, y, z })).
*/
LLGL_EXPORT int NumMipLevels(const Gs::Vector3i& textureSize);

/**
\brief Returns true if the specified texture format is a compressed format,
i.e. either RGB_DXT1, RGBA_DXT1, RGBA_DXT3, or RGBA_DXT5.
\see TextureFormat
*/
LLGL_EXPORT bool IsCompressedFormat(const TextureFormat format);


} // /namespace LLGL


#endif



// ================================================================================
