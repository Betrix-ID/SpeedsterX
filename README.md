> ![git text](/src/img/IFS.png)


<h1>⚡ SpeedsterX - Automatic Device Optimization Utility</h1>

<p><strong>Version:</strong> 1.0 [ SpeedsterX Custom Idle ]<br>
<strong>Author:</strong> SpeedsterX Team<br>
<strong>License:</strong> &copy; 2025 SpeedsterX Project. All rights reserved.</p>

<hr/>

> [!NOTE]
> **Description:**
> - Script C++ ini dibuat untuk mengoptimalkan perangkat Android secara otomatis dengan mengatur mode idle dan whitelist aplikasi berdasarkan prioritas yang dipilih.
<hr/>

> [!IMPORTANT]
> **Features:**
> 1. **Whitelist system apps**: Memastikan aplikasi sistem tetap berjalan saat mode idle.
> 2. **Whitelist user apps**: Memungkinkan aplikasi pengguna tetap aktif meskipun dalam mode idle.
> 3. **Performance optimization**: Mengoptimalkan konsumsi daya dan meningkatkan kinerja aplikasi yang penting.
> 4. **Safe & Reversible**: Tidak memodifikasi sistem secara permanen (dapat dibatalkan).
> 5. **Lightweight**: Skrip sederhana yang tidak membebani sumber daya perangkat.
> - *Efektivitas dapat bervariasi tergantung pada perangkat dan firmware sistem.*
<hr/>

> [!TIP]
> **Tips Before Use:**
> - Pastikan perangkat Android kamu sudah mengaktifkan `adb shell`.
> - Beberapa perangkat mungkin membutuhkan akses root untuk fungsi maksimal.
> - Gunakan pada perangkat yang mendukung kontrol idle melalui adb/sysfs.
<hr/>

> [!WARNING]
> **License & Credit Notice:**
> - Jika Anda ingin menggunakan atau menyertakan script ini dalam proyek lain/module, harap mencantumkan **credit** kepada pembuat asli.
> - Penggunaan tanpa izin atau perubahan tanpa mencantumkan sumber **adalah pelanggaran**.
> - Penulis tidak bertanggung jawab atas kerusakan/perubahan pada perangkat akibat penggunaan script ini.
<hr/>

<h2>🚀 Usage</h2>

<pre><code>SpeedsterX [OPTION]
</code></pre>

<table>
<thead>
<tr><th>Option</th><th>Description</th></tr>
</thead>
<tbody>
<tr><td><code>-d</code></td><td>Whitelist aplikasi sistem untuk memastikan stabilitas saat idle dengan mode <strong>high priority</strong>.</td></tr>
<tr><td><code>-L</code></td><td>Whitelist aplikasi pengguna agar tetap aktif saat perangkat dalam mode <strong>low priority idle</strong>.</td></tr>
<tr><td><code>-R</code></td><td>Reset semua perubahan yang telah dilakukan oleh SpeedsterX ke <strong>default</strong>.</td></tr>
<tr><td><code>-h</code>, <code>--help</code></td><td>Tampilkan bantuan penggunaan.</td></tr>
</tbody>
</table>

<hr/>

<h2>📚 Example Commands</h2>

<pre><code># Whitelist aplikasi sistem (high priority)
SpeedsterX -d

# Whitelist aplikasi pengguna (low priority)
SpeedsterX -L

# Reset semua pengaturan SpeedsterX
SpeedsterX -R
</code></pre>

<hr/>

<h2>ℹ️ More Info</h2>

<ul>
<li><a href="https://developer.android.com/studio/command-line/adb" target="_blank">Android Developer Documentation</a></li>
<li><a href="https://source.android.com/docs/core/power/app_mgmt?hl=id" target="_blank"> Android Open Source Idle</a></li>
<li><a href="https://stackoverflow.com/questions/tagged/android" target="_blank">Stack Overflow Help & Q&A</a></li>
</ul>

<hr/>
