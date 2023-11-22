entry_point:
  ALLOCA_COORDS_AND_COLORS x1
  ALLOCA x2 100
  ALLOCA x3 1200
  XOR x4 x4 x4
  BR main_loop
main_loop:
  SET_ZEROS x2 100
  SET_ZEROS x3 1200
  XOR x6 x6 x6
  BR points_loop
points_loop:
  MULI x30 x6 3
  LOAD_I32 x12 x1 x30 0
  LOAD_I32 x13 x1 x30 1
  LOAD_I32 x14 x3 x30 0
  LOAD_I32 x15 x3 x30 1
  LOAD_I32 x16 x3 x30 2
  XOR x8 x8 x8
  ADDI x8 x8 -2
  BR points_loop_y
points_loop_y:
  MUL x17 x8 x8
  ADD x18 x8 x13
  XOR x10 x10 x10
  ADDI x10 x10 -2
  BR points_loop_x
points_loop_x:
  MUL x19 x10 x10
  ADD x20 x19 x17
  XOR x31 x31 x31
  ADDI x31 x31 4
  GT x21 x20 x31
  BR_COND x21 not_in_circle in_circle
in_circle:
  ADD x22 x10 x12
  XOR x31 x31 x31
  SET_PIXEL x22 x18 x31
  EQ x23 x0 x31
  BR_COND x23 not_in_circle painted
painted:
  MULI x30 x6 3
  ADD x14 x14 x22
  STORE_I32 x14 x3 x30 0
  ADD x15 x15 x18
  STORE_I32 x15 x3 x30 1
  ADDI x16 x16 1
  STORE_I32 x16 x3 x30 2
  BR not_in_circle
not_in_circle:
  INC_EQ x11 x10 2
  BR_COND x11 end_x_loop_points points_loop_x
end_x_loop_points:
  INC_EQ x9 x8 2
  BR_COND x9 end_points points_loop_y
end_points:
  INC_EQ x7 x6 100
  XOR x30 x30 x30
  ADDI x30 x30 2
  BR_COND x7 50 points_loop
48:
  XOR x31 x31 x31
  EQ x31 x17 x31
  BR_COND x31 update_buffer 50
50:
  ADDI x30 x30 1
  XOR x31 x31 x31
  ADDI x31 x31 -1
  XOR x19 x30 x31
  MUL x33 x30 x30
  XOR x29 x29 x29
  XOR x28 x28 x28
  BR 55
55:
  ADDI x15 x29 0
  LOAD_I8 x14 x2 x15 0
  XOR x31 x31 x31
  EQ x31 x14, x31
  ADDI x17 x28 0
  BR_COND x31 61 107
61:
  MULI x13 x29 3
  LOAD_I32 x10 x1 x13 0
  LOAD_I32 x11 x1 x13 1
  LOAD_I32 x12 x1 x13 2
  XOR x21 x21 x21
  ADDI x26 x19 0
  BR 71
71:
  MUL x27 x26 x26
  ADD x32 x26 x11
  ADDI x24 x21 0
  ADDI x34 x19 0
  BR 79
79:
  MUL x31 x34 x34
  ADD x31 x31 x27
  GT x31 x31 x33
  ADDI x18 x24 0
  BR_COND x31 97 85
76:
  ADDI x20 x26 1
  EQ x31 x26 x30
  ADDI x21 x18 0
  ADDI x26 x20 0
  BR_COND x31 101 71
85:
  ADD x35 x34 x10
  SET_PIXEL x35 x32 x12
  OR x25 x0 x24
  XOR x31 x31 x31
  EQ x31 x0 x31
  ADDI x18 x25 0
  BR_COND x31 97 90
90:
  LOAD_I32 x14 x3 x13 0
  ADD x14 x14 x35
  STORE_I32 x14 x3 x13 0
  LOAD_I32 x14 x3 x13 1
  ADD x14 x14 x32
  STORE_I32 x14 x3 x13 1
  LOAD_I32 x14 x3 x13 2
  ADDI x14 x14 1
  STORE_I32 x14 x3 x13 2
  ADDI x18 x25 0
  BR 97
97:
  ADDI x22 x34 1
  EQ x31 x34 x30
  ADDI x24 x18 0
  ADDI x34 x22 0
  BR_COND x31 76 79
101:
  XOR x31 x31 x31
  EQ x14 x18 x31
  ADDI x31 x31 1
  XOR x31 x14 x31
  STORE_I8 x14 x2 x15 0
  OR x23 x28 x31
  ADDI x17 x23 0
  BR 107
107:
  ADDI x28 x17 0
  ADDI x29 x29 1
  XOR x31 x31 x31
  ADDI x31 x31 100
  EQ x31 x29 x31
  BR_COND x31 48 55
update_buffer:
  UPDATE_GPU_BUFFER
  XOR x6 x6 x6
  BR next_iteration_center
next_iteration_center:
  MULI x30 x6 3
  LOAD_I32 x7 x3 x30 0
  LOAD_I32 x8 x3 x30 2
  DIV x9 x7 x8
  STORE_I32 x9 x1 x30 0
  LOAD_I32 x9 x3 x30 1
  DIV x9 x9 x8
  STORE_I32 x9 x1 x30 1
  INC_EQ x31 x6 100
  BR_COND x31 next_iteration_center_end next_iteration_center
next_iteration_center_end:
  FLUSH
  INC_EQ x5 x4 100
  BR_COND x5 exit main_loop
exit:
  RET