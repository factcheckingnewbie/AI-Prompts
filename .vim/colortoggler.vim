" colortoggler.vim - Toggle dynamic color schemes
" Author: Unknown
" Last Modified: Date Unknown

" Function to set active dynamic colors
" This function can be called with or without arguments
" If called without arguments, it will disable all dynamic color groups
" If called with a group name, it will activate that group
function! SetActiveDynamicColors(...)
  " Check if any arguments were passed
  let group_name = a:0 > 0 ? a:1 : ''
  
  " If group_name is empty, clear all dynamic groups and echo a disabled message
  if empty(group_name)
    " Clear all dynamic color groups
    let g:active_dynamic_colors = {}
    echo "Dynamic colors disabled"
  else
    " Define the requested group
    let g:active_dynamic_colors = {group_name: 1}
    echo "Activated dynamic color group: " . group_name
  endif
endfunction

" Map the command :DynColors to call the function
command! -nargs=? DynColors call SetActiveDynamicColors(<f-args>)

" Optional: Map <leader>d0 to call the function without arguments
nnoremap <leader>d0 :call SetActiveDynamicColors()<CR>