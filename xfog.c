// SPDX-License-Identifier: MIT

/*
 * X.Org, Freedom of Geometry
 *
 * Copyright (C) 2022 Harry Kurn <alternate-se7en@pm.me>
 * https://github.com/owl4ce/xfog
 *
 */

#define _GNU_SOURCE
#include <dlfcn.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

Status XGetWMNormalHints(Display *dpy, Window w, XSizeHints *hp, long *rp) {
    static typeof (XGetWMNormalHints) *orig;
    Status r;
    if(!orig) orig = dlsym(RTLD_NEXT, "XGetWMNormalHints");
    if((r = orig(dpy, w, hp, rp)))
        hp->flags &= ~PResizeInc;
    return r;
}

void XSetWMNormalHints(Display *dpy, Window w, XSizeHints *hp) {
    static typeof (XSetWMNormalHints) *orig;
    if(!orig) orig = dlsym(RTLD_NEXT, "XSetWMNormalHints");
    hp->flags &= ~PResizeInc;
    orig(dpy, w, hp);
}
