<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8"/>
  <meta name="viewport" content="width=device-width,initial-scale=1"/>
  <title>Dhun - Select Your Mood</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      background: url('https://cdn.magicdecor.in/com/2023/02/30001557/image-1681372079-229.jpg') center/cover fixed;
      display:flex;align-items:center;justify-content:center;height:100vh;margin:0;
    }
    .container {
      width:92%; max-width:900px; padding:26px; border-radius:14px;
      background: rgba(255,255,255,0.88); box-shadow:0 12px 30px rgba(0,0,0,0.18); backdrop-filter: blur(8px);
      text-align:center;
    }
    h1{ margin:0 0 6px; font-size:1.9rem; color:#2d3436; }
    p{ margin-top:0;color:#666 }
    form { display:flex; gap:14px; flex-wrap:wrap; justify-content:center; margin-top:18px }
    select {
      min-width:200px; padding:12px; border-radius:10px; border:1.8px solid #e6e6e6; font-size:15px;
    }
    button {
      padding:12px 18px; border-radius:10px; border:0; color:#fff; font-weight:700; cursor:pointer;
      background: linear-gradient(45deg,#4ecdc4,#44a08d); min-width:220px; font-size:16px;
    }
    button:hover { transform:translateY(-3px) }
    .playlist-btn {
      padding:12px 18px; border-radius:10px; border:0; color:#fff; font-weight:700; cursor:pointer;
      background: linear-gradient(45deg,#4ecdc4,#44a08d); min-width:220px; font-size:16px; margin-top:18px;
    }
    .playlist-btn:hover { transform:translateY(-3px) }
    @media(max-width:600px){ select { min-width:100%; } button{ min-width:100% } .playlist-btn { min-width:100%; } }
  </style>
</head>
<body>
  <div class="container">
    <h1>Customize Your Dhun Experience</h1>
    <p>Pick your mood, year, and language to create the perfect playlist!</p>

    <form id="selectionForm">
      <select id="mood" required>
        <option value="">Select Your Mood</option>
        <option value="joyful">Joyful 😄</option>
        <option value="sad">Sad 😢</option>
        <option value="workout">Workout ⚡</option>
        <option value="romantic">Romantic 💕</option>
        <option value="party">Party 🎉</option>
      </select>

      <select id="year" required>
        <option value="">Select Year</option>
        <option value="80-90">80-90</option>
        <option value="90-2000">90-2000</option>
        <option value="2000-2025">2000-2025</option>
      </select>

      <select id="language" required>
        <option value="">Select Language</option>
        <option value="english">English</option>
        <option value="hindi">Hindi</option>
        <option value="marathi">Marathi</option>
        <option value="punjabi">Punjabi</option>
      </select>

      <button type="submit">Generate Playlist</button>
    </form>
    <div id="playlistContainer"></div>
  </div>

  <script>
   const playlists = {
  "joyful-80-90-english": "https://open.spotify.com/playlist/0ClU06lWFnw960AfWsqx9M?si=dgrU1UWXTeazW5-vgzWuCw",
  "joyful-80-90-hindi": "https://open.spotify.com/playlist/2otxjJvEQuCQD7yoZVDJSM?si=KNOH8s7zTcqRvLfLjCdSyAi",
  "joyful-80-90-marathi": "https://open.spotify.com/playlist/5qbMWW1sBa4fWdKkUTIm6u?si=kRwgXVeoTE61o7GOrS175w&pi=rC5ufFOQRBuSD",
  "joyful-80-90-punjabi": "https://open.spotify.com/playlist/0nzlLTCgWXjVICICZMLlCI?si=WzM-_2XUSry_hNGub7ml8Q",

  "joyful-90-2000-english": "https://open.spotify.com/playlist/2TfjEh5uTF2gFBkVZRngt3?si=8s3MyG2mTGOtUscbpqGLsw",
  "joyful-90-2000-hindi": "https://open.spotify.com/playlist/7H0aBCTv3xs1CnnCKkePrl?si=AiS3ycUvSBqKtC1Po5rE0g",
  "joyful-90-2000-marathi": "https://open.spotify.com/playlist/5qbMWW1sBa4fWdKkUTIm6u?si=kRwgXVeoTE61o7GOrS175w&pi=rC5ufFOQRBuSD",
  "joyful-90-2000-punjabi": "https://open.spotify.com/playlist/6U1dEywEefiOnaXedgqkdn?si=Yk4iCnWaRcW5DkZo2D2sHA",

  "joyful-2000-2025-english": "https://open.spotify.com/playlist/2gEhbiic3JteObzaovaiOf?si=h7SCQnQvTwui269quWAltQ",
  "joyful-2000-2025-hindi": "https://open.spotify.com/playlist/2HXECsRbw1A1JhPCxmGH5B?si=UTMpnJ1LQca4ygY2_jQQ-g",
  "joyful-2000-2025-marathi": "https://open.spotify.com/playlist/5qbMWW1sBa4fWdKkUTIm6u?si=kRwgXVeoTE61o7GOrS175w&pi=rC5ufFOQRBuSD",
  "joyful-2000-2025-punjabi": "https://open.spotify.com/playlist/0rTNkJJGlqUsI6YdjMnlcT?si=WdIGu5E1QcuIMpfEiKK2Lg",

  "sad-80-90-english": "https://open.spotify.com/playlist/6qxmquYjZZV8M9sTMUhgEa?si=oxDXY44qQou8PNe2HaXFJg",
  "sad-80-90-hindi": "https://open.spotify.com/playlist/0fCG10Gy6EsM6Gv5NXluW3?si=xXmvQkY6T5enszetcVuGmg",
  "sad-80-90-marathi": "https://open.spotify.com/playlist/6a0IK9nFl9WxJyvmfuXAcD?si=3I-fdFuNQMu-EkEC82vx_g&pi=B-h6HtqORhqAT",
  "sad-80-90-punjabi": "https://open.spotify.com/playlist/4aK5LFoeasSrgZrixPIPOW?si=dpCtMTTGSyeYXIkcr0hERg",

  "sad-90-2000-english": "https://open.spotify.com/playlist/7MTQtVxqkeFsFwGWzcqFTL?si=doGALrY3S0-ENO3W6qfDRw",
  "sad-90-2000-hindi": "https://open.spotify.com/playlist/64m4UvzSeWPDaNj8MumFUt?si=yQA08fjsRrGnVnee55Kzwg",
  "sad-90-2000-marathi": "https://open.spotify.com/playlist/1EAGZIKmwxxN6uWXYw9YSw?si=FmVCyg_RSfauGXbh-wS68w&pi=AYUMvIK0TmG00",
  "sad-90-2000-punjabi": "https://open.spotify.com/playlist/1k1c9xdWFIku6BGcUBq3yx?si=ybK-36M4TAWALsn9jTtDDw",

  "sad-2000-2025-english": "https://open.spotify.com/playlist/2U8oYPgDcuJ4FVCGUoi2wg?si=mY5bCpmaT9GdDYTSO5p3Cg",
  "sad-2000-2025-hindi": "https://open.spotify.com/playlist/20fTRutqHJxNvrABs8vjcf?si=08b8WemoQyGOYuW7jjKhGQ",
  "sad-2000-2025-marathi": "https://open.spotify.com/playlist/04ohzBlbo7FlzgBpTRUqO4?si=2nreklnST32A07hg9iepAA&pi=cjR_HrW2QQOOl",
  "sad-2000-2025-punjabi": "https://open.spotify.com/playlist/04EaU4dlrXMq2nuaWmZ2H9?si=S5IIM0N9SyKkCgyxQ4N__Q",

  "workout-80-90-english": "https://open.spotify.com/playlist/5PVT4S1sgo86UMexUsKCDO?si=A6KOYOrOQ-SGgxqaothWqw",
  "workout-80-90-hindi": "https://open.spotify.com/playlist/1l9UfNmZOsGVqktU0FRw1y?si=v4qoM-mxRPKc0H_ZD0jdYA",
  "workout-80-90-marathi": "https://open.spotify.com/playlist/6qMZfAuvBsvGdvfzpyxZlp?si=atR7oXtsTnanFxr2bnI97g&pi=eDViHQfFQE619",
  "workout-80-90-punjabi": "https://open.spotify.com/playlist/2ipyibmI7tzsD2jQB7EJcC?si=YyXC_rzrRjy3hry_DAGDcg",

  "workout-90-2000-english": "https://open.spotify.com/playlist/3O57qb4Sx9lXZlEGhqdqy4?si=ih8MtxW5S-eMjqd_MI57uw",
  "workout-90-2000-hindi": "https://open.spotify.com/playlist/24GDvVFsXc5hvor3odYqLw?si=_WMG-jJGQT6egoPH8gmKxg",
  "workout-90-2000-marathi": "https://open.spotify.com/playlist/0VAD2FtqmaG8i8xjpaN35u?si=9We0VqPXQIuuSJHQO5CUtg&pi=PBK8qOTNTy-v-",
  "workout-90-2000-punjabi": "https://open.spotify.com/playlist/39PTBPyXuThrS4xrKXViqn?si=l4UZEFckSpSDo2JXRIynSg",

  "workout-2000-2025-english": "https://open.spotify.com/playlist/0wJdRd4xNE6HMOEwijsszh?si=BJrQREUqTgaliGDOoAza5A",
  "workout-2000-2025-hindi": "https://open.spotify.com/playlist/6xMGu1VBid7wILKHBRiSKu?si=zYIDGNI3QqG7TiAsg98L1Q",
  "workout-2000-2025-marathi": "https://open.spotify.com/playlist/5GFz63H4QEBB4uEZMpatr8?si=yb3Wm8UxQIGzy6QPUgv0yQ&pi=qhdRCJeBTLuJG",
  "workout-2000-2025-punjabi": "https://open.spotify.com/playlist/1ZPxeldb2S5z2Ad9ZA9X9h?si=s4fL7VS4Tw2gMUPMJefCCQ",

  "romantic-80-90-english": "https://open.spotify.com/playlist/78W9TWPD6fLbHEZyPMfpl9?si=Z6kLbayhSYSabLlGZpJy6w",
  "romantic-80-90-hindi": "https://open.spotify.com/playlist/5G6HEakraoeEHC5bpC4XFR?si=0hPX9aSORzG7uCO_aP0lNA",
  "romantic-80-90-marathi": "https://open.spotify.com/playlist/7qShFK83F0rD9pEgeFCLZy?si=VaQaWc_MTfOWQn6-7XhbTA&pi=MxQwTRvnRmu-D&pt=7986d69150dd7d931554937a2df7b102",
  "romantic-80-90-punjabi": "https://open.spotify.com/playlist/3qubEzCzjpZMFUSmhw0DVR?si=7YTtiKEEQVSGzZhQ7rFMfg",

  "romantic-90-2000-english": "https://open.spotify.com/playlist/4rIkOrBUxTayivXx3MXKuc?si=O9kvIyZwRLCkQcmjDvHetA",
  "romantic-90-2000-hindi": "https://example.com/playlist4https://open.spotify.com/playlist/0mhaAzW2fOfATzwJSI8M91?si=SxQbA9LETFK7_y-7muxNHg",
  "romantic-90-2000-marathi": "https://open.spotify.com/playlist/0tw317cZzEJG7PJO7bwU6u?si=Yo8AVDvyQ1Wprl7-uNI2fA&pi=fLLD1ArASR2wI",
  "romantic-90-2000-punjabi": "https://open.spotify.com/playlist/4XXndVDPJchVcnwa8mTXdX?si=A9DoRCWoSqKl_ElyOwuYDw",

  "romantic-2000-2025-english": "https://open.spotify.com/playlist/4XeiLxkEqLeBbuznZjGH3R?si=smXCwkdxRki1HNQhasoMCg",
  "romantic-2000-2025-hindi": "https://open.spotify.com/playlist/1svPsVs0WgdRYLNdaWm9Mf?si=22_Ph3KlRua-hbb-zlypRg",
  "romantic-2000-2025-marathi": "https://open.spotify.com/playlist/6t7W0CnNFMREZp546SaYCm?si=E2QfKIHmToWUWRr4YT4Y5w&pi=9so4gr4ZTpGTk",
  "romantic-2000-2025-punjabi": "https://open.spotify.com/playlist/4Je1E4fzVWXOo73BqrClCk?si=z_OwDe57R4yGdDdMmJKebw",

  "party-80-90-english": "https://open.spotify.com/playlist/382IIP9WXBQGHI07cXqPDj?si=lMXD8FGbQh2fljt2A8z5dQ",
  "party-80-90-hindi": "https://open.spotify.com/playlist/5v5eblBBMGu3NYUySYStPb?si=CrX1ZHXhS-6yDd7UgrDF_w",
  "party-80-90-marathi": "https://open.spotify.com/playlist/1raCZAEzOuz3Iq9H5ZYBmy?si=eSBO9QuaR0Op6_Gp8NGgDA&pi=xUcemwzDQz-So",
  "party-80-90-punjabi": "https://open.spotify.com/playlist/2zb4IkoKYpLcaivb8k9ecO?si=7gqpEPwDQ6-tAAGxwWJQwQ",

  "party-90-2000-english": "https://open.spotify.com/playlist/2Y1wEy0WA9EKWH3T169oUd?si=qinbAFT7QLmoewwyIq29yQ",
  "party-90-2000-hindi": "https://open.spotify.com/playlist/5v5eblBBMGu3NYUySYStPb?si=moI-5f88T7-LIPuaQM1Qbg",
  "party-90-2000-marathi": "https://open.spotify.com/playlist/4r3BadKWVOKHKF0j82NCHd?si=2CA0nYbfSqK29lSgOeXrsA&pi=nxYLJK5eSq-DM",
  "party-90-2000-punjabi": "https://open.spotify.com/playlist/60FO2RzZamDLxaJutQAw0N?si=9OiDjNKBS0i0HB9p7TK4Kg",

  "party-2000-2025-english": "https://open.spotify.com/playlist/1te36FSIu60NKxZnn02L2l?si=kFtmEKuaRjuafBe9gG6CnA",
  "party-2000-2025-hindi": "https://open.spotify.com/playlist/68a4iK18ybIQapAg2IBs5l?si=OfKOkMN-QOCTIUhy6u-ioQ",
  "party-2000-2025-marathi": "https://open.spotify.com/playlist/6qRi7y1Lp9uVULmwfs3jhf?si=Cz3Q-7V2TmmB2JgcbgHUiA&pi=avTitGspQhugl",
  "party-2000-2025-punjabi": "https://open.spotify.com/playlist/4EBlShLJvyQeje3FQdnGKD?si=vG4oVDEjTkeP_8sJSLoIKg"
};

    document.getElementById('selectionForm').addEventListener('submit', function(event) {
      event.preventDefault();
      const mood = document.getElementById('mood').value;
      const year = document.getElementById('year').value;
      const language = document.getElementById('language').value;
      const key = `${mood}-${year}-${language}`;
     
      const container = document.getElementById('playlistContainer');
      container.innerHTML = ''; // Clear previous button
     
      if (playlists[key]) {
        const btn = document.createElement('button');
        btn.textContent = 'Click here for the playlist!!';
        btn.classList.add('playlist-btn');
        btn.onclick = () => window.location.href = playlists[key];
        container.appendChild(btn);
      }
    });
  </script>
</body>
</html>      
