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

function addItem(event) {
    const numberInput = document.getElementById('listNumber');
    const nameInput = document.getElementById('itemName');
    const message = document.getElementById('message');

    const num = parseInt(numberInput.value, 10);
    const name = nameInput.value.trim();

    message.textContent = "";

    if (name.length === 0) {
        message.textContent = "Введите название пункта.";
        return false;
    }

    if (name.length > 10) {
        message.textContent = "Ошибка: название не должно превышать 10 символов.";
        return false;
    }

    if (num < 0) {
        message.textContent = "Ошибка: введите корректный номер списка.";
        return false;
    }

    if (num === 0) {
        const ol = document.querySelector("ol");
        const id = document.querySelectorAll("ol > li").length;

        const li = document.createElement("li");
        li.innerHTML = `${name} <span id='btn-${id}' class='toggle' onclick='toggleList(${id})'>[+]</span>`

        const ul = document.createElement("ul");
        ul.id = `list-${id}`;
        ul.classList.add("hidden");

        li.appendChild(ul);
        ol.appendChild(li);
        message.textContent = "Добавлен новый список первого уровня.";
        return false;
    }

    const targetList = document.getElementById('list-' + (num - 1));
    if (!targetList) {
        message.textContent = "Ошибка: списка с таким номером не существует.";
        return false;
    }

    const newItem = document.createElement("li");
    newItem.textContent = name;
    targetList.appendChild(newItem);
    message.textContent = "Элемент успешно добавлен.";

    return false;
}
