set nu
set ts=2
set autoindent
set hlsearch

set nocompatible
filetype off
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'scrooloose/nerdcommenter'
call vundle#end()
filetype plugin indent on

let mapleader = ","
