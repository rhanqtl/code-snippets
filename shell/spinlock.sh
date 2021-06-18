#!/usr/bin/env bash

# set -ex

sleep 3

touch /tmp/lock.0

port=5001
locked="false"
while [[ "${port}" -lt 65536 ]]; do
  ln /tmp/lock.0 ./lock."${port}" &>/dev/null
  if [[ "$?" -eq 0 ]]; then
    echo "process $$ lock on port ${port}"
    locked="true"
    break
  fi
  port=$((port + 1))
done

if [[ "${locked}" == "false" ]]; then
  echo "process $$ failed to lock"
  exit 1
fi
