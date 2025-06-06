🛑 自動終止遊戲進程工具

這是一個用 C 語言 編寫的程式，可自動檢測並強制終止特定的遊戲進程。

---

📌 功能

✅ 自動監控：每秒檢測一次目標進程是否運行。

✅ 強制終止：如果發現指定的遊戲進程，將立即關閉它們。

✅ 列出所有進程：運行時顯示目前所有系統進程，幫助確認目標進程是否存在。

✅ 輕量級設計：無需額外安裝，只需執行可執行檔案即可運行。


---

🎯 支援的遊戲進程

此程式會監控並終止以下遊戲的可執行檔案：

> 📢 如果需要添加新的進程，請在 GitHub Issues 提交請求！




---

🔧 使用方式

1️⃣ 運行程式

Windows 10 / 11 用戶直接執行 Project3.exe。

以管理員身份運行，確保擁有終止進程的權限。


2️⃣ 監控與終止進程

程式會每秒檢測一次指定的遊戲進程，若發現它們運行，將會 立即終止。

終端將顯示當前系統運行的所有進程，可手動確認目標遊戲是否運行。


3️⃣ 停止程式

手動關閉命令提示字元窗口 (Cmd)

使用 Ctrl + C 強制終止程式



---

⚠ 注意事項

🚨 請確保程式擁有管理員權限，否則可能無法終止某些遊戲進程。

🚨 此工具僅適用於個人用途，請勿用於非法行為！

🚨 此程式會持續運行，如需停止，請手動關閉 (Ctrl + C)



---

📢 常見問題 (FAQ)

❓ 為什麼程式無法終止某些遊戲？

某些遊戲進程受到保護，可能需要手動進入 任務管理器 來終止。此外，請確保你以 管理員身份運行 程式。

❓ 如何新增需要終止的進程？

在 GitHub Issues 創建新問題，提供你希望終止的遊戲名稱。

我們會在後續版本中考慮添加！



---

📌 開發資訊

適用系統：Windows 10 / 11

開發語言：C (WinAPI)

最新版本：👉 點此下載


📢 有任何問題？歡迎提交 GitHub Issues！ 🚀

