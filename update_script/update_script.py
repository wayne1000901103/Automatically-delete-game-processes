import os
import requests

# 下載檔案的 URL
url = "https://github.com/wayne1000901103/Automatically-delete-game-processes/releases/latest/download/run_killer.exe"
download_path = "run_killer.exe"

def download_file(url, download_path):
    try:
        print(f"開始下載檔案：{url}")
        
        # 發送 HTTP 請求以獲取檔案
        response = requests.get(url, stream=True)
        
        # 檢查回應狀態碼
        if response.status_code != 200:
            print(f"下載失敗，HTTP 錯誤代碼：{response.status_code}")
            return False
        
        # 儲存下載的檔案
        with open(download_path, "wb") as f:
            for chunk in response.iter_content(chunk_size=1024):
                if chunk:
                    f.write(chunk)
        
        print(f"檔案已成功下載並儲存到 {download_path}")
        return True
    
    except requests.exceptions.RequestException as e:
        print(f"下載過程中發生錯誤：{e}")
        return False

def main():
    print("檢查更新中...")
    
    # 嘗試下載檔案
    success = download_file(url, download_path)
    
    if success:
        print("更新成功！")
    else:
        print("更新失敗：無法下載檔案。")
    
if __name__ == "__main__":
    main()
