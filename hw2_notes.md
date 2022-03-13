# Notes

- So it seems like we have to implement functions that return specific values 
  where our "this" pointer is const 
  My best guess is that this means that we should let our member vectors be
  mutable

  `mutable` is a storage class specificer. Basically it allows const functions
  to modified `mutable` member variables. I guess this is usefull when most data
  members should const with only the few `mutable` exceptions.

# TODOs

- [ ]  Make sure that your makefiles is picking up the changes
    - Tests show that is okay but go through it
- [ ] Make sure make files dont echo the commands they execute, Im not sure if
  this is a requirement but might as well clean that up 
