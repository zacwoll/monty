# div fails on division by zero
push 1
push 0
push 5
pall # 5 0 1
div
pall # fails on 5
