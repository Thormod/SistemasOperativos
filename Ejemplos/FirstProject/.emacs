
;;
;; Emacs columns, lines, goto-line
;;
(setq column-number-mode t)
;;
;; Biding keys to commands
;;
(global-set-key (kbd "<f5>") 'compile)
(global-set-key (kbd "<f6>") 'recompile)
;;
;; auctex
;;
(setq TeX-auto-save t)
(setq TeX-parse-self t)
(setq-default TeX-master nil)

(add-hook 'LaTeX-mode-hook 'visual-line-mode)
(add-hook 'LaTeX-mode-hook 'flyspell-mode)
(add-hook 'LaTeX-mode-hook 'LaTeX-math-mode)
;;
;; changing pdf viso
;;
(setq TeX-view-program-list '(("Evince" "evince --page-index=%(outpage) %o")))
(setq TeX-view-program-selection '((output-pdf "Evince")))
;;
;; Enable RefTex
;;
(require 'reftex)
(add-hook 'LaTeX-mode-hook 'turn-on-reftex)
(setq reftex-plug-into-AUCTeX t)
;;
;; Enable TeX-PDF-mode
;;
(setq TeX-PDF-mode t)
;;
;; emacs repositories
;;
(setq package-archives '(("gnu" . "http://elpa.gnu.org/packages/")
			 ("marmalade" . "https://marmalade-repo.org/packages/")
			 ("melpa" . "http://melpa.org/packages/")))
;;
;; Setting font
;;
(set-face-attribute 'default nil :height 120)
;;
;; Setting font mini-buffer
;;
(add-hook 'minibuffer-setup-hook 'my-minibuffer-setup)
(defun my-minibuffer-setup ()
      (set (make-local-variable 'face-remapping-alist)
          '((default :height 1.0))))
;;
;; ensime
;;
;;(require 'ensime)
;; (add-hook 'scala-mode-hook 'ensime-scala-mode-hook)
;;
;; inf-ruby
(autoload 'inf-ruby-minor-mode "inf-ruby" "Run an inferior Ruby process" t)
(add-hook 'ruby-mode-hook 'inf-ruby-minor-mode)
(add-hook 'enh-ruby-mode-hook 'inf-ruby-minor-mode)
(add-hook 'after-init-hook 'inf-ruby-switch-setup)

;;
;;
(load "/home/fcardona/.emacs.d/personal/beamer.el")
