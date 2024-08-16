// Copyright (C) 2023-2024 Stdware Collections (https://www.github.com/stdware)
// Copyright (C) 2021-2023 wangwenx190 (Yuhang Zhao)
// SPDX-License-Identifier: Apache-2.0

#ifndef WINDOWWindowbarButtonPrivate_H
#define WINDOWWindowbarButtonPrivate_H

#include "windowbutton.h"

namespace QWK {

    class WindowWindowbarButtonPrivate {
        Q_DECLARE_PUBLIC(WindowButton)
    public:
        WindowWindowbarButtonPrivate();
        virtual ~WindowWindowbarButtonPrivate();

        void init();

        WindowButton *q_ptr;

        QIcon iconNormal;
        QIcon iconChecked;
        QIcon iconDisabled;

        void reloadIcon();
    };

}

#endif // WINDOWWindowbarButtonPrivate_H