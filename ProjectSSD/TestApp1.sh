#! /bin/bash

(echo fullwrite 0x13131313; echo fullread; echo exit) | ./Test
