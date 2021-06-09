# function _debug() {
#   echo -e "$(_curr_time)  \x1b[1;33mDEBUG\x1b[0m  $1"
# }

function _info() {
  echo -e "$(_curr_time)  \x1b[1mINFO\x1b[0m   $1"
}

function _warn() {
  echo -e "$(_curr_time)  \x1b[1;33mWARN\x1b[0m   $1"
}

function _error() {
  echo -e "$(_curr_time)  \x1b[1;31mERROR\x1b[0m  $1"
}

function _fatal() {
  _error "$1"  
  exit 1
}
