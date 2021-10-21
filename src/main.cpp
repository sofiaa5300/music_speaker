#include <sqlite3.h>
#include <stdio.h>
#include <gst/gst.h>
#include <iostream>
#include <string>

int callback(void *, int, char **, char **);
static const char *dir_speaker, *directory;

int main(int argc, char* argv[]) {
    gst_init(&argc, &argv);

    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open("test.db", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", 
                sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }

    for (int i = 1; i < argc; i++) {
      directory = argv[i];
      std::string str;
      std::string str1="SELECT DIRECTORY FROM COMPANY where ID=";
      std::string str2=directory;

      // used in the same order as described above:
      str.append(str1);
      str.append(str2);
    
      const char *array = str.c_str();
      const char *sql= array;
        
      rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

      if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);
        
        return 1;
    } 
    
    sqlite3_close(db);
    
    return 0;
   }

}

int gst() {

      GstElement *pipeline = nullptr;
      GstBus *bus = nullptr;
      GstMessage *msg = nullptr;
      
      std::string str;
      std::string str1="playbin uri=file://";
      std::string str2=dir_speaker;
      std::string str3=" ";
      std::string str4="volume = 0.1";

      // used in the same order as described above:
      str.append(str1);
      str.append(str2);
      str.append(str3);
      str.append(str4);

      const char *c_convert = str.c_str();
      std::cout << c_convert;

      // building pipeline
      pipeline = gst_parse_launch(c_convert ,
            nullptr);

      // start playing
      gst_element_set_state(pipeline, GST_STATE_PLAYING);

      //wait until error or EOS ( End Of Stream )
      bus = gst_element_get_bus(pipeline);
      msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE,
                                     static_cast<GstMessageType>(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

      // free memory
      if (msg != nullptr)
      gst_message_unref(msg);
      gst_object_unref(bus);
      gst_element_set_state(pipeline, GST_STATE_NULL);
      gst_object_unref(pipeline);

      return 0;
}



int callback(void *NotUsed, int argc, char **argv,
                    char **azColName) {
    
    NotUsed = 0;

    for (int i = 0; i < argc; i++) {
      dir_speaker = argv[i];
      gst ();
    }
    
    printf("\n");
    return 0;
}

