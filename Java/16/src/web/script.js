function toggleList(id) {
    const list = document.getElementById('list-' + id);
    const btn = document.getElementById('btn-' + id);
    if (list.classList.contains('hidden')) {
        list.classList.remove('hidden');
        btn.textContent = '[-]';
    } else {
        list.classList.add('hidden');
        btn.textContent = '[+]';
    }
}
