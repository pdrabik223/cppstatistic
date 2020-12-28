function GenGrid(how_many_rows) {
    let col = 2,
        rows = how_many_rows;

    for (let i = 0; i < how_many_rows; i++) // wiersze
    {
        let div = document.createElement('div');
        div.className = 'row';
        for (let j = 0; j < cols; j++) //kolumny
        {
            let div1 = document.createElement('div');
            div1.className = 'chart-container';
            div1.className = 'col-lg-6';
            let canvas = document.createElement('canvas');
            canvas.id = 'myChart' + i + j;

            let button = document.createElement('input');
            button.type = 'button';
            button.value = 'Click me';
            button.style.float = 'right';
            div.appendChild(canvas);
            div.body.appendChild(button);
            document.body.appendChild(div);
        }
    }
}


var ctx = document.getElementById('myChart00').getContext('2d');
var obj;


fetch("data.json")
    .then(function(resp) {
        return resp.json();
    })
    .then(function(date) {

        obj = date;

        var myLineChart = new Chart(ctx, {
            type: 'line',
            data: {
                labels: obj.data.x,

                datasets: [{

                    label: obj.name,
                    data: obj.data.y,

                    borderColor: 'red',
                    backgroundColor: 'red',
                    borderWidth: 0.5,
                    fill: false
                }],
            },
            options: {

            }

        });



    })

//-----------------------------------------------------

var ctx2 = document.getElementById('myChart01').getContext('2d');
var obj2;


fetch("data2.json")
    .then(function(resp) {
        return resp.json();
    })
    .then(function(date) {
        obj2 = date;




        var myLineChart = new Chart(ctx2, {
            type: 'line',
            data: {
                labels: obj2.data.x,
                datasets: [{
                        label: obj2.name,
                        data: obj2.data.y,
                        borderColor: 'blue',
                        backgroundColor: 'blue',
                        borderWidth: 0.5,
                        fill: false

                    }

                ],
            },
            options: {

            }

        });



    })