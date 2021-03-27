var gulp = require('gulp');

var handleErrors = require('../util/handleErrors');

var config = require('../config').html;

var dependents = require('gulp-dependents');

const htmlMin = require('gulp-html-minifier-terser');


function htmlFunc() {
	return gulp.src(config.src, { since: gulp.lastRun(htmlFunc) })
		.pipe(dependents())
  	    .pipe(htmlMin({ collapseWhitespace: true }))
		.pipe(gulp.dest(config.dest))
}

//Обязательно экспортируем
exports.htmlTask = htmlFunc;