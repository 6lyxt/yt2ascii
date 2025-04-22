# yt2ascii
c++ tool to play a youtube video in terminal (as ascii art)

## prerequisites
- opencv
- ffmpeg
- yt-dlp

## build
```bash
$ g++ -std=c++17 main.cpp -o yt2ascii `pkg-config --cflags --libs opencv4`
```

## usage
```bash
$ ./play.sh https://www.youtube.com/watch/?v\=G3-jWRbc3Uw
```
