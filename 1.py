import requests

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/132.0.0.0 Safari/537.36",
    "X-Csrf-Token": "f8b21f7d6de4a2e8aaa093fd3f9e8dbd",
    "Cookie": "_gid=GA1.2.1268623988.1738420988; JSESSIONID=A40FCBB3BA34B6313F84EAFEF4803237; 39ce7=CFjldzmI; evercookie_png=3fndbjq7grd8dt5fv9; evercookie_etag=3fndbjq7grd8dt5fv9; evercookie_cache=3fndbjq7grd8dt5fv9; 70a7c28f3de=3fndbjq7grd8dt5fv9; lastOnlineTimeUpdaterInvocation=1738491973209; cf_clearance=jbTFtoX06DPxCD_hIwp5Mw64pWeN744adU1UXT3mQqM-1738493180-1.2.1.1-XkHeeKH5iJTJNaO50II9w8LtPyaz6zK3GnDC6b2oKuLLuR9y7nq2TnFkxz1LiNB9jqIBT4n3.l610wwd96Wms63aiFoEhW8Lce2hDtpoFrDSMM3TIz5GveuTi0J99fOWkujH2M3nMr.Q_n2PHw2ReiAJERBVyeFSTeBw7wM8c0VmI0GeMKRsqBGV_ExfL2MBIVvtsGYuz.5RwpCTbIDbizH8WDpFwFJ_HLIKshVKSSbCh_b5u3EkkrMTCjZzDrK_lylU0uIYzFKmHdGq5Au6_rboYM4IL3E.p3WGpSSBJ0kuKtJVP7isAdNbtJ3Z8U69IHtDVemW_MG5HYgtXt.sug; _gat_gtag_UA_743380_5=1; pow=740fc4630d55296dbb2dc89a01d39d32d069a06c; X-User-Sha1=b635dc333843ab1236b0e308aeb990205d880d34; X-User=f9f216c94f49f45f54698a8f2707e48caa9428094933ffc2f69369c70f0bf4cb47256105e0c68a19;",
}
dat = {
    "submissionId": "304037365",
    "csrf-token": "f8b21f7d6de4a2e8aaa093fd3f9e8dbd",
}
resp = requests.post(url="https://codeforces.com/data/submitSource", data=dat, headers=headers)
print(resp.status_code)
print(resp.text)