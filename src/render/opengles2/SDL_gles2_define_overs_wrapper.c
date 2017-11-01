

#include "SDL_gles2_define_overs_wrapper.h"

int LoadContext(GLES2_Context * data)
{
#if SDL_VIDEO_DRIVER_UIKIT
#define __SDL_NOGETPROCADDR__
#elif SDL_VIDEO_DRIVER_ANDROID
#define __SDL_NOGETPROCADDR__
#elif SDL_VIDEO_DRIVER_PANDORA
#define __SDL_NOGETPROCADDR__
#endif

#if defined __SDL_NOGETPROCADDR__
#define SDL_PROC(ret,func,params) data->func=func;
#else
#define SDL_PROC(ret,func,params) \
    do { \
        data->func = SDL_GL_GetProcAddress(#func); \
        if ( ! data->func ) { \
            return SDL_SetError("Couldn't load GLES2 function %s: %s", #func, SDL_GetError()); \
        } \
    } while ( 0 );
#endif /* __SDL_NOGETPROCADDR__ */
#include "SDL_gles2funcs.h"
#undef SDL_PROC
//    my_context = data;
    return 0;
}

#endif // HAVE_OPENGLES2
