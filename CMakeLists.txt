project (music_sqlite)
cmake_minimum_required(VERSION 2.8)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

ADD_EXECUTABLE(music_sqlite
               /home/sofia/sqlite/src/main.cpp)

include_directories(music_sqlite PUBLIC
                    /usr/local/oecore-x86_64/sysroots/cortexa7hf-neon-vfpv4-poky-linux-gnueabi/usr/include
                    /usr/local/oecore-x86_64/sysroots/cortexa7hf-neon-vfpv4-poky-linux-gnueabi/usr/include/gstreamer-1.0/gst
                    /usr/local/oecore-x86_64/sysroots/cortexa7hf-neon-vfpv4-poky-linux-gnueabi/usr/include/glib-2.0
                    /usr/local/oecore-x86_64/sysroots/cortexa7hf-neon-vfpv4-poky-linux-gnueabi/usr/lib/glib-2.0/include      
                    /usr/local/oecore-x86_64/sysroots/cortexa7hf-neon-vfpv4-poky-linux-gnueabi/usr/include/gstreamer-1.0
                    )

target_link_libraries(music_sqlite
                    /usr/local/oecore-x86_64/sysroots/cortexa7hf-neon-vfpv4-poky-linux-gnueabi/usr/lib/libsqlite3.so                    
                    /usr/local/oecore-x86_64/sysroots/cortexa7hf-neon-vfpv4-poky-linux-gnueabi/usr/lib/libgstnet-1.0.so
                    /usr/local/oecore-x86_64/sysroots/cortexa7hf-neon-vfpv4-poky-linux-gnueabi/usr/lib/libglib-2.0.so
                    /usr/local/oecore-x86_64/sysroots/cortexa7hf-neon-vfpv4-poky-linux-gnueabi/usr/lib/libgstreamer-1.0.so

)