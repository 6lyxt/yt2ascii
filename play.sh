#!/bin/bash

VIDEO_URL="$1"
WORKDIR="yt2ascii_temp"

mkdir -p "$WORKDIR"
echo "Downloading video..."
yt-dlp -f 'best[height<=720]' -o "$WORKDIR/video.%(ext)s" "$VIDEO_URL"

VIDEO_FILE=$(ls "$WORKDIR" | grep -E '\.mp4$|\.mkv$|\.webm$' | head -n1)

echo "Extracting frames..."
mkdir -p "$WORKDIR/frames"
ffmpeg -i "$WORKDIR/$VIDEO_FILE" -vf "fps=30,scale=240:-1" "$WORKDIR/frames/frame_%04d.png"

echo "Playing video in ASCII..."
./yt2ascii "$WORKDIR/frames"

echo "Cleaning up..."
rm -rf "$WORKDIR"
