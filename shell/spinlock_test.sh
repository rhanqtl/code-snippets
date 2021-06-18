#!/usr/bin/env zs ;

if [[ -z "${NPS}" ]]; then
  NPS=256
fi

for _ in $(seq 1 "${NPS}"); do
  timeout -k 1s 5s bash ../spinlock.sh &>>$$.log &
done
