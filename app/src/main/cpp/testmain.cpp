#include <jni.h>
#include <string>

void testfreetype();

extern "C" jstring Java_com_test_freetype271_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */) {

    testfreetype();

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

#include <android/log.h>
#include <ft2build.h>
#include FT_FREETYPE_H

void testfreetype() {
    FT_Library library;
    FT_Error ret = FT_Init_FreeType(&library);
    __android_log_print(ANDROID_LOG_DEBUG, "aaaaa", "aaaaa FT_Init_FreeType() ret=%d", ret);

    FT_Face s_face;
    ret = FT_New_Face( library, "/data/local/rounded-mgenplus-1pp-regular.ttf", 0, &s_face );
    __android_log_print(ANDROID_LOG_DEBUG, "aaaaa", "aaaaa FT_New_Face() ret=%d", ret);

    // 幅と高さ 水平解像度
    ret = FT_Set_Char_Size( s_face, 0, 16*64, 300,300 );
    __android_log_print(ANDROID_LOG_DEBUG, "aaaaa", "aaaaa FT_Set_Char_Size() ret=%d", ret);

    FT_UInt glyph_index = FT_Get_Char_Index( s_face, 'q' );
    ret = FT_Load_Glyph( s_face, glyph_index, FT_LOAD_DEFAULT );
    __android_log_print(ANDROID_LOG_DEBUG, "aaaaa", "aaaaa FT_Load_Glyph() ret=%d", ret);

    FT_GlyphSlot slot = s_face->glyph;
    ret = FT_Render_Glyph( slot, FT_RENDER_MODE_NORMAL );
    __android_log_print(ANDROID_LOG_DEBUG, "aaaaa", "aaaaa FT_Render_Glyph() ret=%d", ret);

    if( slot->format != FT_GLYPH_FORMAT_BITMAP )
        __android_log_print(ANDROID_LOG_DEBUG, "aaaaa", "aaaaa slot->format=%d", slot->format);

    FT_Bitmap bitmap = slot->bitmap;
    __android_log_print(ANDROID_LOG_DEBUG, "aaaaa", "aaaaa width=%d height=%d", slot->bitmap.width, slot->bitmap.rows);


}