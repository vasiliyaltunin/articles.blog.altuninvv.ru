var gulp = require('gulp');

var Sass = require('./sass.js');
var Js = require('./js.js');
var Html = require('./html.js');

console.log("Gulp init...");

gulp.task('default',
    gulp.series(
        Sass.sassTask,
        Js.jsTask,
        Html.htmlTask)
);

