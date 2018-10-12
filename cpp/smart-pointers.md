### Smart Pointers Usage

#### unique_ptr

Can not be copied, no memory overhead. 
Can use custom deletion functions.

#### shared_ptr

Uses reference counting. Each shared_optyr contains 2 ptr: one to target and one to control block, which contains ref count and weak ref count.
Use make_shared to create all the object in one call.
Contains 2 pointers:
1. To the object inself
2. To the control block, which contains ref_count & weak_ref_count. Access to those fields must be thread safe (usually with the help of atomic), 
so every copy of shared_ptr may cause thread block.

#### Avoid passing smart pointers into functions.

There are 5 main patterns

1. Use. Pass a reference (const) or a raw pointer.
2. May share. Pass a const ref to shared_ptr.
3. Share. Pass shared_ptr by value.
4. Reset. Pass ref to shared_ptr or ref to unique_ptr.
5. Take. Pass unique_ptr by value (actually it will be moved)

