#include "database.h"

// Simple forwarding wrapper functions
Movie* insert_movie(const char* title) {
    return create_movie(title);
}
