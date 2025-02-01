    for (int i = 0; i < acknowledgementSize; i++) {
        printf("\033[F\033[K"); // ANSI escape codes to move cursor up and clear line
        fflush(stdout);         // Ensure output is updated immediately
        usleep(90000);          // 50 milliseconds delay between lines
    }

    for (int i = 0; i < headerSize; i++) {
      
        printf("\033[F\033[K"); // ANSI escape codes to move cursor up and clear line
        fflush(stdout);         // Ensure output is updated immediately
        usleep(90000);          // 50 milliseconds delay between lines
    }