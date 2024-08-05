/*****************************************************************//**
 * \file   style_core_types.h
 * \brief  ����ͷ�ļ�
 * 
 * \author C3H3_Ttigone
 * \date   August 2024
 *********************************************************************/

#ifndef STYLE_CORE_TYPES_H
#define STYLE_CORE_TYPES_H

namespace style {

using string = QString;
using rect = QRect;
using point = QPoint;
using size = QSize;
using cursor = Qt::CursorShape;
using align = Qt::Alignment;
using margins = QMargins;
//using font = internal::Font;
//using owned_font = internal::OwnedFont;
//using color = internal::Color;
//using owned_color = internal::OwnedColor;
//using complex_color = internal::ComplexColor;
//using icon = internal::Icon;

static constexpr cursor cur_default = Qt::ArrowCursor;
static constexpr cursor cur_pointer = Qt::PointingHandCursor;
static constexpr cursor cur_text = Qt::IBeamCursor;
static constexpr cursor cur_cross = Qt::CrossCursor;
static constexpr cursor cur_sizever = Qt::SizeVerCursor;
static constexpr cursor cur_sizehor = Qt::SizeHorCursor;
static constexpr cursor cur_sizebdiag = Qt::SizeBDiagCursor;
static constexpr cursor cur_sizefdiag = Qt::SizeFDiagCursor;
static constexpr cursor cur_sizeall = Qt::SizeAllCursor;

}


#endif  // STYLE_CORE_TYPES_H
